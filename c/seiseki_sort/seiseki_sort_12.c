#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>


/*学籍番号(num),点数(score),平均点(average)の構造体*/
typedef struct{
  int num;
  int *score;
  double average;
}student;


/*関数プロトタイプ*/
int question(void);//最初の質問
int yes_no(void);//0か1を入力させて分岐させる関数
void score_judge(student a[], int stu, int sub);//点数入力のエラー処理用関数


void manual_input(student a[], int stu, int sub);//マニュアル入力で成績データを打たせる関数
void random_input(student a[], int stu, int sub);//乱数で成績データを作る関数
void external_data_input(student a[], int stu, int sub);//外部ファイルからデータを持ってくる関数
void input(student a[], int stu, int sub);//入力系統の総まとめ


void cut_crlf(char* buff);//改行を取り除く関数
void get_row_col(FILE* fp, int* row, int* col);//csvファイルの縦横のサイズをカウント


void average_student(student a[], int stu, int sub);//その生徒の平均点を計算する用
void average_subject(student a[], double average[], int stu, int sub);//その教科の平均点を計算する用


void swap(student *a, student *b);//数字を交換する関数
void bubble_sort(student a[], int stu);//バブルソートの関数
void sort_progress(student a[], int stu);


int external_data_output(student a[], int stu, int sub);//外部ファイルの作成をする関数
int average_data_output(student a[], double average[], int stu, int sub);//平均点を計算したあとのファイル作成
int sort_data_output(student a[], double average[], int stu, int sub);//ソートしたあとのファイル作成
void output(student a[], double average[], int stu, int sub);//ターミナルに結果を表示させる用関数

  /*------------------------------------main文------------------------------------*/
int main(void){
  int student_num,subject_num;//生徒数，教科数
  int row,col=0;
  int i;
  int judge,flag;
  char key;
  student *data;//入力された生徒数分の点数データを確保する用
  double *ave_subject;//入力された教科数分の平均点データを確保する用
  double sort_time;//ソート時間を格納
  struct timeval start,end;//プログラムの開始時間，終了時間
  FILE *fp;//ファイルポインタ


  while(1){

    /*プログラムスタート*/
    flag = question();
    if(flag==0){//外部ファイル読み込みの分岐
      if((fp = fopen("data.csv", "r")) == NULL){
        printf("ファイルをオープンできません．\ndata.csvのファイルが存在しないか，保存場所が異なっている可能性があります．\ndata.csvが存在しない場合，(1)を選択してcsvファイルを作成してください．\n\n");
        continue;
      }else{
        get_row_col(fp, &row, &col);
        printf("data.csvは生徒数が%d人，教科数が%d教科の成績データです．\nこの設定で処理を始めます．何か文字を入力してEnter．\n", row, col-1);
        scanf("%s", &key);
        student_num = row;
        subject_num = col-1;
      }
    }else{//自分で入力する分岐
      while(1){
        printf("生徒は何人ですか？：");
        scanf("%d", &student_num);
        printf("何教科ですか？：");
        scanf("%d", &subject_num);
        if(0<student_num && 0<subject_num){
          break;
        }else{
          printf("0以下の入力はしないでください\n");
        }
      }
    }
    printf("\n");

    /*メモリの確保*/
    data = malloc(sizeof(student) * student_num);
    for(i=0;i<student_num;i++){
      data[i].score = malloc(sizeof(int) * subject_num);
    }
    ave_subject = malloc(sizeof(double) * subject_num);


    if(flag==0){
     if((fp = fopen("data.csv", "r")) == NULL){
       printf("ファイルをオープンできません．\ndata.csvのファイルの保存場所をもう一回確認してください．\n\n");
       continue;
     }else{
      external_data_input(data, student_num, subject_num);
    }
  }else{
    input(data, student_num, subject_num);
  }
  printf("\n");

    /*平均を計算*/
  average_student(data, student_num, subject_num);
  average_subject(data, ave_subject, student_num, subject_num);


    /*出力(ソート前)*/
  printf("~ソート前~\n");
  output(data, ave_subject, student_num, subject_num);
  printf("\n");
  printf("ソート前の平均点を計算した成績データを保存しますか？\n");
  if(yes_no()==0){
    average_data_output(data, ave_subject, student_num, subject_num);
  }
  printf("\n");

    /*ソート*/
  if(student_num>=20000){
    printf("ソート中...\n");
    gettimeofday(&start, NULL);//時間計測の開始
    sort_progress(data, student_num);
    gettimeofday(&end, NULL);//時間計測の終了
    printf("ソートが完了しました．何か文字を入力してEnter．\n");
    scanf("%s", &key);
  }else{
    gettimeofday(&start, NULL);//時間計測の開始
    bubble_sort(data, student_num);
    gettimeofday(&end, NULL);//時間計測の終了

  }

    /*出力(ソート後)*/
    printf("~ソート後~\n");
    output(data, ave_subject, student_num, subject_num);
    printf("\n");
    printf("ソート後の成績データを保存しますか？\n");
    if(yes_no()==0){
      sort_data_output(data, ave_subject, student_num, subject_num);
    }
    printf("\n");

    sort_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)*1.0E-6;
    printf("ソートするのにかかった時間は%lf[s]でした．\n", sort_time);


    printf("もう一回やりますか？\n");
    if(yes_no()==1){
      printf("おつかれさまでした．\n");
      break;
    }
  }
  printf("\n\n");

  /*確保したメモリの開放*/
  free(ave_subject);
  for(i=0;i<student_num;i++){
    free(data[i].score);
  }
  free(data);


  return 0;
}

/*------------------------------------ここから関数------------------------------------*/

int question(void){
  int judge;

  printf("外部ファイルから読み込んでソート\t\t\t・・・(0)\n成績データを入力してソート(作成した成績データの保存)\t・・・(1)\n");
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


int yes_no(void){
  int judge;

  printf("はい・・・(0)，いいえ・・・(1)\n");
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


void external_data_input(student a[], int stu, int sub){
  FILE *fp;
  int i,j;


  if((fp = fopen("data.csv", "r")) == NULL){
    printf("ファイルをオープンできません．\ndata.csvのファイルの保存場所をもう一回確認してください．\n");
  }else{
    for(i=0;i<stu;i++){
      fscanf(fp, "%d", &a[i].num);
      fscanf(fp, ",");
      for(j=0;j<sub-1;j++){
        fscanf(fp, "%d", &a[i].score[j]);
        fscanf(fp, ",");
      }
      fscanf(fp, "%d", &a[i].score[sub-1]);
      fscanf(fp,"\n");
    }
    fclose(fp);
  }
}


void input(student a[], int stu, int sub){
  int judge,retry=0;
  int i,j;

  while(1){
    printf("成績データを手入力\t\t\t・・・(0)\n乱数で自動的に成績データを作成(確認用)\t・・・(1)\n");
    scanf("%d", &judge);
    if(judge==0){
      manual_input(a, stu, sub);
      printf("入力された成績データを保存しますか？\n");
      if(yes_no()==0){
        external_data_output(a, stu, sub);
      }
      break;
    }else if(judge==1){
      random_input(a, stu, sub);
      printf("乱数で成績データを作成しました\n成績データを保存しますか？\n");
      if(yes_no()==0){
        external_data_output(a, stu, sub);
      }
      break;
    }else{
      printf("0,1のいずれかを入力してください\n");
    }
  }
}




void cut_crlf(char *buff){
  int i;
  for(i=0;i<strlen(buff);i++){
    if(buff[i]=='\n'){
      buff[i] = 0;
    }
  }
}


void get_row_col(FILE *fp, int *row, int *col){
  int data;
  char buf[512];
  char *token;

  rewind(fp);
  *row = *col = 0;
  while(fgets(buf,256,fp)){
    cut_crlf(buf);
    if(*row == 0){
      token = (char*)strtok(buf, ",");
      while(token!=NULL){
        sscanf(token, "%d", &data);
        token = (char*)strtok(NULL, ",");
        *col = *col + 1;
      }
    }
    *row = *row + 1;
  }
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
  int i,j;

  for(i=0;i<stu-1;i++){
    for(j=stu-1;i<j;j--){
      if(a[j-1].average>a[j].average){
        swap(&a[j-1], &a[j]);
      }
    }
  }
}


void sort_progress(student a[], int stu){
  int i,j;
  int progress;
  int grogress_count;
  int percent;

  setbuf(stdout,NULL);
  grogress_count = stu/20;

  for(j=0;j<20;j++){
    printf("□");
  }
  printf("   0 ％\r");


  for(i=0;i<stu-1;i++){
    for(j=stu-1;i<j;j--){
      if(a[j-1].average>a[j].average){
        swap(&a[j-1], &a[j]);
      }
    }
    progress = i%(stu/20);
    if(progress==grogress_count-1){
      for(j=1;j<=i/(grogress_count)+1;j++){
        printf("■");
      }
      for(j=1;j<=20-(i/(grogress_count)+1);j++){
        printf("□");
      }
      percent = (float)i/stu * 100;
      printf("%4d ％",percent);
    }
    printf("\r");
  }

  for(j=0;j<20;j++){
    printf("■");
  }
  printf(" 100 ％\n");
  printf("\x1b[2B");

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