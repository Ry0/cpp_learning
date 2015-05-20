#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

  /*学籍番号(num),点数(score),平均点(average)の構造体*/
typedef struct{
  int num;
  int *score;
  double average;
}student;

  /*点数入力のエラー処理用関数*/
void score_judge(student a[], int stu, int sub){
  while(1){//0~100までの点数を入力させる
    printf("%d番目の人の%d教科目の点数を入力：", stu+1, sub+1);
    scanf("%d", &a[stu].score[sub]);
    if(0<=a[stu].score[sub] && a[stu].score[sub]<=100){
      break;
    }else{
      printf("不正な点数です。打ち直し。\n");
    }
  }
}

  /*データ入力*/
void input(student a[], int stu, int sub){
  int judge,retry=0;
  int i,j;

  do{
    printf("成績データをマニュアル入力・・・(0) 乱数で一連の動作を確認・・・(1)\n");
    scanf("%d", &judge);
    if(judge==0){
      for(i=0;i<stu;i++){
        a[i].num = i+1;//生徒番号を1から順に番号つけ
        for(j=0;j<sub;j++){
          score_judge(a, i, j);
        }
        printf("\n");
      }
      retry=0;
    }else if(judge==1){
      srand((unsigned) time(NULL));//時刻によって乱数の種を変更
      for(i=0;i<stu;i++){
        a[i].num = i+1;//生徒番号を1から順に番号つけ
        for(j=0;j<sub;j++){
          a[i].score[j] = rand()%100+1;//1から100までの乱数を発生
        }
      }
      retry = 0;
    }else{
      printf("0か1を入力してください\n");
      retry = 1;
    }
  }while(retry==1);
}

  /*生徒ごとの平均点計算*/
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

  /*教科ごとの平均点計算*/
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

  /*数値の交換*/
void swap(student *a, student *b){
  student temp;

  temp = *a;
  *a = *b;
  *b = temp;
}

  /*ソート*/
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

  /*データ出力*/
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


int main(void){
  int student_num,subject_num;//生徒数、教科数
  int i;
  student *data;//入力された生徒数分の点数データを確保する用
  double *ave_subject;//入力された教科数分の平均点データを確保する用
  double sort_time;
  struct timeval start,end;

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


  input(data, student_num, subject_num);

  average_student(data, student_num, subject_num);
  average_subject(data, ave_subject, student_num, subject_num);


  printf("~ソート前~\n");
  output(data, ave_subject, student_num, subject_num);
  printf("\n");

  gettimeofday(&start, NULL);//時間計測の開始
  bubble_sort(data, student_num);
  gettimeofday(&end, NULL);//時間計測の終了

  printf("~ソート後~\n");
  output(data, ave_subject, student_num, subject_num);
  printf("\n");

  sort_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)*1.0E-6;
  printf("ソートするのにかかった時間は%lf[s]でした.\n", sort_time);

  /*確保したメモリの開放*/
  free(data);
  for(i=0;i<student_num;i++){
    free(data[i].score);
  }
  free(ave_subject);

  return 0;
}
