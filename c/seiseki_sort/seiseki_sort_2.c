#include <stdio.h>
#include <stdlib.h>
#include <time.h>

  /* 学籍番号(num),点数(score),平均点(average)の構造体 */
typedef struct{
  int num;
  int *score;
  double average;
} student;

  /* 数値の交換 */
void swap(student *a, student *b){
  student temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

  /* ソート */
void bubble_sort(student a[], int student_num){
  int i,j,k;
  for(i=0; i<student_num-1; i++){
    for(j=student_num-1; i<j; j--){
      if(a[j-1].average>a[j].average){
       swap(&a[j-1], &a[j]);
     }
   }
 }
}

  /* データ出力 */
void output(student a[], int student_num, int subject){
  int i,j;
  printf("生徒\t");
  for(j=1;j<=subject;j++){
    printf("教科%d\t", j);
  }
  printf("平均\t");
  printf("\n");


  for(i=0;i<student_num;i++){
    printf("%2d\t", a[i].num);
    for(j=0;j<subject;j++){
      printf("%3d\t", a[i].score[j]);
    }
    printf("%3.2lf\t", a[i].average);
    printf("\n");
  }

  for(i=0;i<subject+2;i++){
    printf("--------");
  }
  printf("\n");

}

void output_adress(student a[], int student_num, int subject){
  int i,j;
  printf("生徒\t");
  for(j=1;j<=subject;j++){
    printf("教科%d\t", j);
  }
  printf("平均\t");
  printf("\n");


  for(i=0;i<student_num;i++){
    printf("%p\t", &a[i].num);
    for(j=0;j<subject;j++){
      printf("%p\t", &a[i].score[j]);
    }
    printf("%p\t", &a[i].average);
    printf("\n");
  }

  for(i=0;i<subject+2;i++){
    printf("--------");
  }
  printf("\n");

}

int main(void){

  int student_num,subject=0;//生徒数、教科数
  student *data;
  double *ave_student;
  int i,j=0;
  int sum = 0;


  printf("生徒は何人ですか？:");
  scanf("%d", &student_num);
  printf("何教科ですか？:");
  scanf("%d", &subject);


  /* メモリの確保 */
  data = malloc(sizeof(student) *student_num);
  for(i=0;i<student_num;i++){
    data[i].score = malloc(sizeof(int) *subject);
  }

  ave_student = malloc(sizeof(double) *subject);

  srand((unsigned) time(NULL));

  /* データ入力と計算 */
  for(i=0;i<student_num;i++){
    data[i].num = i+1;//生徒番号を1から順に番号つけ
    for(j=0;j<subject;j++){
      data[i].score[j] = rand()%100+1;

     //  while(1){//0~100までの点数を入力させる
     //   printf("%d番目の人の%d教科目の点数を入力:", i+1, j+1);
     //   scanf("%d", &data[i].score[j]);
     //   if(0<=data[i].score[j] && data[i].score[j]<=100){
     //     break;
     //   }else{
     //     printf("不正な点数です。打ち直し。\n");
     //   }
     // }

      sum = sum + data[i].score[j];//その生徒の全教科の合計点を計算
    }
    data[i].average = (double)sum/subject;//その生徒の平均点を計算
    sum = 0;
    //printf("\n");
  }

  /* 教科ごとの平均点計算 */
  sum = 0;
  for(i=0;i<subject;i++){
    for(j=0;j<student_num;j++){
      sum = sum + data[j].score[i];
    }
    ave_student[i] = (double)sum/student_num;
    sum = 0;
  }

  printf("ソート前\n");
  output(data,student_num,subject);
  printf("平均\t");
  for(i=0;i<subject;i++){
    printf("%3.2lf\t", ave_student[i]);
  }
  printf("\n\n");

  bubble_sort(data, student_num);

  printf("ソート後\n");
  output(data,student_num,subject);
  printf("平均\t");
  for(i=0;i<subject;i++){
    printf("%3.2lf\t", ave_student[i]);
  }
  printf("\n");

  /* 確保したメモリの開放 */
  free(data);
  for(i=0;i<student_num;i++){
    free(data[i].score);
  }
  free(ave_student);

  return 0;
}
