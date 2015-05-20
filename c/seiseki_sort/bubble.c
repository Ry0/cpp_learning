#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM_OF_PERSON 10000
#define NUM_OF_SUBJECT 5

typedef struct {
	int num;
	double score[NUM_OF_SUBJECT];
	double ave;
} person_t;

double SumArray(double a[]){
	int i;
	double s=0.0;
	for(i=0;i<NUM_OF_SUBJECT;i++){
		s += a[i];
	}
	return s;
}

void SwapPerson(person_t *a, person_t *b){
	person_t temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void ScoreAverage(person_t p[]){
	int i;
	for(i=0;i<NUM_OF_PERSON;i++){
		p[i].ave = SumArray(p[i].score)/NUM_OF_SUBJECT;
	}
}

void DataRandomize(person_t p[]){
	srand((unsigned) time(NULL));
	int i,j;
	for(i=0;i<NUM_OF_PERSON;i++){
		for(j=0;j<NUM_OF_SUBJECT;j++){
			p[i].score[j] = rand()%101;
		}
	}
}

void DataBubbleSort(person_t p[]){
	int i,j;
	for(i=0;i<NUM_OF_PERSON;i++){
		for(j=NUM_OF_PERSON-1;i<j;j--){
			if(p[j].ave<p[j-1].ave) SwapPerson(&p[j],&p[j-1]);
		}
	}
}

void RuleLine(void){
	int i;
	for(i=0;i<NUM_OF_SUBJECT+1;i++){
		printf("--------");
	}
	printf("+-------");
	printf("\n");
}

void DisplayAverage(person_t p[]){
	int i,j;
	double temp;
	person_t averageman;
	for(j=0;j<NUM_OF_SUBJECT;j++){
		temp=0.0;
		for(i=0;i<NUM_OF_PERSON;i++){
			 temp += p[i].score[j];
		}
		averageman.score[j] = temp/NUM_OF_PERSON;
	}
	RuleLine();
	printf("平均\t");
	for(j=0;j<NUM_OF_SUBJECT;j++){
		printf("%.2lf\t",averageman.score[j]);
	}
	printf("|\n");
	RuleLine();
}

void DataDisplay(person_t p[]){
	int i,j;
	RuleLine();
	printf("番号\t");
	for(i=1;i<=NUM_OF_SUBJECT;i++){
		printf("科目%d\t",i);
	}
	printf("|平均\n");
	RuleLine();
	for(i=0;i<NUM_OF_PERSON;i++){
		printf("%d\t",p[i].num);
		for(j=0;j<NUM_OF_SUBJECT;j++){
			printf("%.0lf\t",p[i].score[j]);
		}
		printf("|%.2lf\n",p[i].ave);
	}
	DisplayAverage(p);
}

void NumberAssign(person_t p[]){
	int i;
	for(i=0;i<NUM_OF_PERSON;i++){
		p[i].num = i+1;
	}
}

int YesOrNo(void){
	char c;

	while(c!='y' && c!='n'){
		printf("(y/n)\n");
		scanf("%s",&c);
		fflush(stdin);
	}
	if(c == 'y') return 1;
	else if(c == 'n')return 0;
	else return -1;
}

int WriteDataFile(person_t p[]){
	int i,j,flag;
	FILE *outputfile;

	outputfile = fopen("./data.csv","r");
	if(outputfile == NULL){
		outputfile = fopen("./data.csv","w");
	}else{
		printf("同名ファイルが存在します。上書きしてよろしいですか？");
		flag = YesOrNo();
		if(flag == 1) outputfile = fopen("./data.csv","w");
		else if(flag == 0) return 1;
		else return -1;
	}

	for(i=0;i<NUM_OF_PERSON;i++){
		for(j=0;j<NUM_OF_SUBJECT-1;j++){
			fprintf(outputfile,"%.0lf,",p[i].score[j]);
		}
		fprintf(outputfile,"%.0lf",p[i].score[NUM_OF_SUBJECT-1]);
		fprintf(outputfile,"\n");
	}
	fclose(outputfile);
	return 0;
}

int WriteSortFile(person_t p[]){
	int i,j,flag;
	FILE *outputfile;

	outputfile = fopen("./result.csv","r");
	if(outputfile == NULL){
		outputfile = fopen("./result.csv","w");
	}else{
		printf("同名ファイルが存在します。上書きしてよろしいですか？");
		flag = YesOrNo();
		if(flag == 1) outputfile = fopen("./result.csv","w");
		else if(flag == 0) return 1;
		else return -1;
	}

	for(i=0;i<NUM_OF_PERSON;i++){
		fprintf(outputfile,"%d,",p[i].num);
		for(j=0;j<NUM_OF_SUBJECT;j++){
			fprintf(outputfile,"%.0lf,",p[i].score[j]);
		}
		fprintf(outputfile,"%lf\n",p[i].ave);
	}
	fclose(outputfile);
	return 0;
}

int ReadDataFile(person_t p[]){
	int i,j;
	FILE *outputfile;

	outputfile = fopen("./data.csv","r");

	if(outputfile == NULL){
		printf("data.csvが存在しない、または読み込みエラーです。\n");
		return -1;
	}
	for(i=0;i<NUM_OF_PERSON;i++){
		for(j=0;j<NUM_OF_SUBJECT-1;j++){
			fscanf(outputfile,"%lf,",&p[i].score[j]);
		}
		fscanf(outputfile,"%lf,",&p[i].score[NUM_OF_SUBJECT-1]);
		fscanf(outputfile,"\n");
	}
	fclose(outputfile);
	return 0;
}


int main(void){
	int i=0;
	person_t student[NUM_OF_PERSON];

	printf("起動オプションを選択してください。\n1：ランダムデータファイルの生成\n2：データ読み込み・ソート\n3：ランダムデータ作成＋ソート結果を表示(ファイル出力しない)\n");
	scanf("%d",&i);
	if(i==1){
		printf("作成したデータは同階層のdata.csvに保存されます。\n");
		DataRandomize(student);
		if(WriteDataFile(student) == 0){
			NumberAssign(student);
			ScoreAverage(student);
			printf("作成データ\n");
			DataDisplay(student);
		}
	}else if(i==2){
		if(ReadDataFile(student) == 0){
			NumberAssign(student);
			ScoreAverage(student);
			printf("読込データ\n");
			DataDisplay(student);
			DataBubbleSort(student);
			printf("ソート結果\n");
			DataDisplay(student);
			printf("番号・平均を含んだソート結果をresult.csvに保存しますか？");
			if(YesOrNo() == 1) WriteSortFile(student);
		}
	}else if(i==3){
		NumberAssign(student);
		DataRandomize(student);
		ScoreAverage(student);
		printf("作成データ\n");
		DataDisplay(student);
		DataBubbleSort(student);
		printf("ソート結果\n");
		DataDisplay(student);
	}else{
		printf("1、2、3のいずれかを入力してください。\n");
	}
	return 0;
}
