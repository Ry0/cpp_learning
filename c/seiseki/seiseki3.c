#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

#define S_NUM 3
#define H_NUM 3

typedef struct{
  double point;
}subject;

typedef struct{
 subject CL[S_NUM];
 int sum;
 double ave;
}human;

char InputDataCheck(double point){
    if( point < 0 || point > 100){
      printf("入力エラーです。point=%lf\n", point);
      return false;
    }else{
      return true;
    }
}

void InputData(human *hito){
  int i,j=0;
  for(i=0; i<H_NUM; i++){
    printf("%d人目\n",i+1);
    for(j=0; j< S_NUM; j++){
      printf("%d科目の点数：",j+1); scanf("%lf", &hito[i].CL[j].point);
      if(InputDataCheck(hito[i].CL[i].point) != true){
        j--;
        continue;
      }
    }
  }
}

void GetHumanAverage(human *hito, human *ave){
  int i,j = 0;
  ave->sum = 0;
  for(i=0; i<H_NUM; i++){
    hito[i].sum = 0;
    for(j=0; j<S_NUM; j++){
     hito[i].sum += hito[i].CL[j].point;
    }
    hito[i].ave = hito[i].sum / (double)S_NUM;
    ave->sum += hito[i].ave;
  }
  ave->ave = ave->sum / (double)H_NUM;
}

void GetSubjectAverage(human *hito, human *ave){
  int i,j = 0;
  int sum = 0;
  for(j=0; j<S_NUM; j++){
    sum = 0;
    for(i=0; i<H_NUM; i++){
      sum += hito[i].CL[j].point;
    }
    ave->CL[j].point = sum/(double)H_NUM;
  }
}

void PrintData(human *hito, human ave){
  int i,j = 0;
  printf("------------------------------------\n");
  for(i=0; i<H_NUM; i++){
    printf("%d人目：\t",i+1);
    for(j=0; j<S_NUM; j++){
      printf("%5.1lf", hito[i].CL[j].point);
    }
    printf("|%5.1lf\n",hito[i].ave);
  }
  printf("------------------------------------\n");
  printf("平均：\t");
  for(j=0; j<S_NUM; j++){
    printf("%5.1lf", ave.CL[j].point);
  }
  printf("\n");
}

int main(void){
  human classmates[H_NUM];
  human averageman;
      
  InputData(classmates);  
  GetHumanAverage(classmates, &averageman);
  GetSubjectAverage(classmates, &averageman);
  PrintData(classmates, averageman);
  return 0;
}
