#include <stdio.h>
#define student 4
#define subject 6

int main(void){
  int a[student][subject+1];
  double ave_student[subject];
  double ave_subject[student];
  int i,j;
  int sum = 0;

  for(i=0;i<student;i++){
    a[i][0] = i+1;
    for(j=1;j<=subject;j++){
      while(1){
       printf("%d番目の人の%d教科目の点数を入力:", i+1, j);
       scanf("%d", &a[i][j]);
       if(0<=a[i][j]&&a[i][j]<=100){
         break;
       }else{
         printf("不正な点数です。打ち直し。\n");
       }
     }
     sum = sum +a[i][j];
   }
   ave_subject[i] = sum/subject;
   sum = 0;
   printf("\n");
 }

 sum = 0;
 for(i=0;i<subject;i++){
  for(j=0;j<student;j++){
    sum = sum +a[j][i+1];
  }
  ave_student[i]=sum/student;
  sum = 0;
}


printf("生徒\t");
for(j=1;j<=subject;j++){
  printf("教科%d\t", j);
}
printf("平均\t");
printf("\n");


for(i=0;i<student;i++){
  for(j=0;j<=subject;j++){
    printf("%3d\t", a[i][j]);
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

return 0;
}
