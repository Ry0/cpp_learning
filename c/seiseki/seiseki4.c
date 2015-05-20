#include <stdio.h>
#include <stdlib.h>

int main(void){
  int *num=0;//生徒番号用
  int **data=0;//[生徒数]×[教科数]のデータ用
  double *ave_student=0;//各教科における全生徒の平均点用(教科数分確保)
  double *ave_subject=0;//生徒自身における全教科の平均点用(生徒数分確保)
  int student,subject=0;//生徒数、教科数
  int i,j=0;
  int sum = 0;

  printf("生徒は何人ですか？:");
  scanf("%d", &student);
  printf("何教科ですか？:");
  scanf("%d", &subject);

  /* メモリの確保 */
  num = malloc(sizeof(double) *student);
  data = malloc(sizeof(double) *student);
  for(i=0;i<student;i++){
    data[i] = malloc(sizeof(double) *subject);
  }

  ave_student = malloc(sizeof(double) *subject);
  ave_subject = malloc(sizeof(double) *student);

  /* データ入力と計算 */
  for(i=0;i<student;i++){
    num[i] = i+1;//生徒番号を1から順に番号つけ
    for(j=0;j<subject;j++){

      while(1){//0~100までの点数を入力させる
	printf("%d番目の人の%d教科目の点数を入力:", i+1, j+1);
	scanf("%d", &data[i][j]);
	if(0<=data[i][j] && data[i][j]<=100){
	  break;
	}else{
	  printf("不正な点数です。打ち直し。\n");
	}
      }

      sum = sum + data[i][j];//その生徒の全教科の合計点を計算
    }
    ave_subject[i] = (double)sum/subject;//その生徒の平均点を計算
    sum = 0;
    printf("\n");
  }

  /* 教科ごとの平均点計算 */
  sum = 0;
  for(i=0;i<subject;i++){
    for(j=0;j<student;j++){
      sum = sum + data[j][i];
    }
    ave_student[i] = (double)sum/student;
    sum = 0;
  }

  /* データ出力 */
  printf("生徒\t");
  for(j=1;j<=subject;j++){
    printf("教科%d\t", j);
  }
  printf("平均\t");
  printf("\n");


  for(i=0;i<student;i++){
    printf("%2d\t", num[i]);
    for(j=0;j<subject;j++){
      printf("%3d\t", data[i][j]);
    }
    printf("%3.2lf\t", ave_subject[i]);
    printf("\n");
  }

  for(i=0;i<subject+2;i++){
    printf("--------");
  }
  printf("\n");

  printf("平均\t");
  for(i=0;i<subject;i++){
    printf("%3.2lf\t", ave_student[i]);
  }
  printf("\n");

  /* 確保したメモリの開放 */
  free(num);
  for(i=0;i<student;i++){
    free(data[i]);
  }
  free(data);
  free(ave_student);
  free(ave_subject);

  return 0;
}
