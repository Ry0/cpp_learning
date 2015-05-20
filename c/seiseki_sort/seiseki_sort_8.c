#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/time.h>

  /*学籍番号(num),点数(score),平均点(average)の構造体*/
typedef struct{
  int num;
  int *score;
  double average;
}student;


  /*関数プロトタイプ*/
void score_judge(student a[], int stu, int sub);//点数入力のエラー処理用関数
int judge01(void);//0か1を入力させて分岐させる関数

void manual_input(student a[], int stu, int sub);//マニュアル入力で成績データを打たせる関数
void random_input(student a[], int stu, int sub);//乱数で成績データを作る関数
void external_data_input(student a[], int stu, int sub);//外部ファイルからデータを持ってくる関数
void cut_crlf(char* buff);
void get_row_col(FILE* fp, int* row, int* col);
int input(student a[], int stu, int sub);//入力系統の総まとめ

int external_data_output(student a[], int stu, int sub);//外部ファイルの作成をする関数
int average_data_output(student a[], double average[], int stu, int sub);//平均点を計算したあとのファイル作成
int sort_data_output(student a[], double average[], int stu, int sub);//ソートしたあとのファイル作成
void output(student a[], double average[], int stu, int sub);//ターミナルに結果を表示させる用関数

void average_student(student a[], int stu, int sub);//その生徒の平均点を計算する用
void average_subject(student a[], double average[], int stu, int sub);//その教科の平均点を計算する用

void swap(student *a, student *b);//数字を交換する関数
void bubble_sort(student a[], int stu);//バブルソートの関数


  /*------------------------------------main文------------------------------------*/
int main(void){
  int student_num,subject_num;//生徒数，教科数
  int i;
  int judge;
  student *data;//入力された生徒数分の点数データを確保する用
  double *ave_subject;//入力された教科数分の平均点データを確保する用
  double sort_time;
  struct timeval start,end;

  while(1){
    while(1){
    printf("生徒は何人ですか？：");
    scanf("%d", &student_num);
    printf("何教科ですか？：");
    scanf("%d", &subject_num);

  /*メモリの確保*/
    data = malloc(sizeof(student) * student_num);
    for(i=0;i<student_num;i++){
      data[i].score = malloc(sizeof(int) * subject_num);
    }

      ave_subject = malloc(sizeof(double) * subject_num);




  if(input(data, student_num, subject_num)!=-1)break;
  }
  printf("\n");

  average_student(data, student_num, subject_num);
  average_subject(data, ave_subject, student_num, subject_num);


  printf("~ソート前~\n");
  output(data, ave_subject, student_num, subject_num);
  printf("\n");
  printf("ソート前の平均点を計算した成績データを保存しますか？");
  if(judge01()==0){
  average_data_output(data, ave_subject, student_num, subject_num);
  }
  printf("\n");


  gettimeofday(&start, NULL);//時間計測の開始
  bubble_sort(data, student_num);
  gettimeofday(&end, NULL);//時間計測の終了


  printf("~ソート後~\n");
  output(data, ave_subject, student_num, subject_num);
  printf("\n");
  printf("ソート後の成績データを保存しますか？");
  if(judge01()==0){
  sort_data_output(data, ave_subject, student_num, subject_num);
  }
  printf("\n");

  sort_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)*1.0E-6;
  printf("ソートするのにかかった時間は%lf[s]でした.\n", sort_time);

  printf("もう一回やりますか？");
  if(judge01()==1){
    break;
  }
}


  /*確保したメモリの開放*/
  free(data);
  for(i=0;i<student_num;i++){
    free(data[i].score);
  }
  free(ave_subject);

  return 0;
}

/*------------------------------------ここから関数------------------------------------*/

void score_judge(student a[], int stu, int sub){
  while(1){//0~100までの点数を入力させる
    printf("%d番目の人の%d教科目の点数を入力：", stu+1, sub+1);
    scanf("%d", &a[stu].score[sub]);
    if(0<=a[stu].score[sub] && a[stu].score[sub]<=100){
      break;
    }else{
      printf("不正な点数です．打ち直し．\n");
    }
  }
}


int judge01(void){
  int judge;
  printf("はい(0)いいえ(1)\n");
  while(1){
    scanf("%d", &judge);
    if(judge==0){
      return 0;
      break;
    }else if(judge==1){
      return 1;
      break;
    }else{
      printf("0か1を入力してください．\n");
    }
  }
}



void manual_input(student a[], int stu, int sub){
  int i,j;
  for(i=0;i<stu;i++){
    a[i].num = i+1;//生徒番号を1から順に番号つけ
    for(j=0;j<sub;j++){
      score_judge(a, i, j);
    }
    printf("\n");
  }
}


void random_input(student a[], int stu, int sub){
  int i,j;
  srand((unsigned) time(NULL));//時刻によって乱数の種を変更
  for(i=0;i<stu;i++){
    a[i].num = i+1;//生徒番号を1から順に番号つけ
    for(j=0;j<sub;j++){
      a[i].score[j] = rand()%100+1;//1から100までの乱数を発生
    }
  }
}


int external_data_input(student a[], int stu, int sub){
  FILE *fp;
  int i,j;
  int row,col;

  if((fp = fopen("data.csv", "r")) == NULL){
    printf("ファイルをオープンできません．\ndata.csvのファイルの保存場所をもう一回確認してください．\n");
    return 1;
  }else{
    get_row_col(fp, &row, &col);
    if(row==stu && col-1==sub){
    for(i=0;i<stu;i++){
      fscanf(fp, "%d", &a[i].num);
      fscanf(fp, ",");
      for(j=0;j<sub-1;j++){
        fscanf(fp, "%d", &a[i].score[j]);
        fscanf(fp, ",");
      }
      fscanf(fp, "%d", &a[i].score[sub-1]);
      fscanf(fp,"\n");
      return 0;
    }
    fclose(fp);
    }else{
      printf("最初に定義した生徒数は%d人、教科数は%d教科ですが、data.csvの生徒数は%d人、教科数は%d教科です。\nもう一度生徒数と教科数を定義してください。\n", stu, sub, row, col-1);
      return -1;
    }
  }
}


void cut_crlf(char* buff){
  int i;
  for(i=0; i<strlen(buff);i++){
    if(buff[i]=='\n'){
      buff[i] = 0;
    }
  }
}


void get_row_col(FILE *fp, int* row, int* col){
  int data;
  char buf[256],*token;

  rewind(fp);
  *row = *col = 0;
  while (fgets(buf,256,fp)){
    cut_crlf(buf);
    if(*row == 0){
      token = (char*)strtok(buf,",");
      while ( token != NULL ) { // buf にトークンがなくなるまで繰り返す
        sscanf(token,"%d",&data);
        token = (char*)strtok(NULL,","); // 次のトークンを取得
        *col += 1;
      }
    }
    *row += 1;
  }
}


void input(student a[], int stu, int sub){
  int judge,retry=0;
  int i,j;
  int flag;

  while(1){
      printf("成績データをマニュアル入力\t・・・(0)\n乱数で一連の動作を確認\t\t・・・(1)\n外部データの読み込みを行う\t・・・(2)\n");
      scanf("%d", &judge);
      if(judge==0){
        manual_input(a, stu, sub);
        printf("入力された成績データを保存しますか？");
        if(judge01()==0){
          external_data_output(a, stu, sub);
        }
        return 0;
        break;
      }else if(judge==1){
        random_input(a, stu, sub);
        printf("乱数で成績データを作成しました\n成績データを保存しますか？");
        if(judge01()==0){
          external_data_output(a, stu, sub);
        }
        return 0;
        break;
      }else if(judge==2){
        external_data_input(a, stu, sub);
        break;
      }else{
        printf("0,1,2のいずれかを入力してください\n");
      }
    }
}



int external_data_output(student a[], int stu, int sub){
  int i,j;
  FILE *fp;

  if((fp = fopen("data.csv", "w")) == NULL){
    printf("ファイルをオープンできません．\n");
    return 1;
  }else{
    for(i=0;i<stu;i++){
      fprintf(fp, "%d", a[i].num);
      fprintf(fp, ",");
      for(j=0;j<sub-1;j++){
        fprintf(fp, "%d", a[i].score[j]);
        fprintf(fp, ",");
      }
      fprintf(fp, "%d", a[i].score[sub-1]);
      fprintf(fp,"\n");
    }
    printf("入力された成績データを保存しました．\n");
    fclose(fp);
    return 0;
  }
}


int average_data_output(student a[], double average[], int stu, int sub){
  int i,j;
  FILE *fp;

  if((fp = fopen("average.csv", "w")) == NULL){
    printf("ファイルをオープンできません．\n");
    return 1;
  }else{
    fprintf(fp, "生徒,");
    for(j=1;j<=sub;j++){
      fprintf(fp, "教科%d,",j);
    }
    fprintf(fp, "平均");
    fprintf(fp, "\n");


    for(i=0;i<stu;i++){
    fprintf(fp, "%3d,", a[i].num);//学生番号を出力
    for(j=0;j<sub;j++){
        fprintf(fp, "%3d,", a[i].score[j]);//各教科の点数を出力
      }
      fprintf(fp, "%3.2lf", a[i].average);//その生徒の平均点を出力
      fprintf(fp, "\n");
    }

    fprintf(fp, "平均,");
    for(i=0;i<sub-1;i++){
      fprintf(fp, "%3.2lf,", average[i]);//各教科の平均点を出力
    }
    fprintf(fp, "%3.2lf", average[sub-1]);
    fprintf(fp, "\n");
    printf("ソートしたデータを保存しました．\n");
    fclose(fp);
    return 0;
  }
}


int sort_data_output(student a[], double average[], int stu, int sub){
  int i,j;
  FILE *fp;

  if((fp = fopen("sort.csv", "w")) == NULL){
    printf("ファイルをオープンできません．\n");
    return 1;
  }else{
    fprintf(fp, "生徒,");
    for(j=1;j<=sub;j++){
      fprintf(fp, "教科%d,",j);
    }
    fprintf(fp, "平均");
    fprintf(fp, "\n");


    for(i=0;i<stu;i++){
    fprintf(fp, "%3d,", a[i].num);//学生番号を出力
      for(j=0;j<sub;j++){
        fprintf(fp, "%3d,", a[i].score[j]);//各教科の点数を出力
      }
      fprintf(fp, "%3.2lf", a[i].average);//その生徒の平均点を出力
      fprintf(fp, "\n");
    }

    fprintf(fp, "平均,");
    for(i=0;i<sub;i++){
      fprintf(fp, "%3.2lf,", average[i]);//各教科の平均点を出力
    }
    fprintf(fp, "%3.2lf", average[sub-1]);
    fprintf(fp, "\n");
    printf("ソートしたデータを保存しました．\n");
    fclose(fp);
    return 0;
  }
}


void output(student a[], double average[], int stu, int sub){
  int i,j;

  printf("生徒\t");
  for(j=1;j<=sub;j++){
    printf("教科%d\t",j);
  }
  printf("平均\t");
  printf("\n");


  for(i=0;i<stu;i++){
    printf("%3d\t", a[i].num);//学生番号を出力
    for(j=0;j<sub;j++){
      printf("%3d\t", a[i].score[j]);//各教科の点数を出力
    }
    printf("%3.2lf\t", a[i].average);//その生徒の平均点を出力
    printf("\n");
  }

  for(i=0;i<sub+2;i++){
    printf("--------");
  }
  printf("\n");
  printf("平均\t");
  for(i=0;i<sub;i++){
    printf("%3.2lf\t", average[i]);//各教科の平均点を出力
  }
  printf("\n");
}



void average_student(student a[], int stu, int sub){
  int i,j;
  int sum = 0;

  for(i=0;i<stu;i++){
    for(j=0;j<sub;j++){
      sum = sum + a[i].score[j];//その生徒の全教科の合計点を計算
    }
    a[i].average = (double)sum/sub;//その生徒の平均点を計算
    sum = 0;
  }
}


void average_subject(student a[], double average[], int stu, int sub){
  int i,j;
  int sum = 0;

  for(i=0;i<sub;i++){
    for(j=0;j<stu;j++){
      sum = sum + a[j].score[i];//その教科についての全生徒合計点を計算
    }
    average[i] = (double)sum/stu;//その教科の平均点を計算
    sum = 0;
  }
}



void swap(student *a, student *b){
  student temp;

  temp = *a;
  *a = *b;
  *b = temp;
}


void bubble_sort(student a[], int stu){
  int i,j,k;

  for(i=0;i<stu-1;i++){
    for(j=stu-1;i<j;j--){
      if(a[j-1].average>a[j].average){
        swap(&a[j-1], &a[j]);
      }
    }
  }
}