#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define true 1
#define false 0

typedef struct{
  double point;
}subject;

typedef struct{
  int num;
  subject *CL;
  int sum;
  double ave;
}human;

const char filename[] = "inputdata.txt";
const char delimiter[] = " ";

int GetNSChar(void);
int Kakunin(void);
int FlagCheck(char flag);
void InputDataSetting(int *student_num, int *subject_num);
char InputDataCheck(double point);
void InputData(human *hito, int student_num, int subject_num);
void InputDataRandom(human *hito, int student_num, int subject_num);
int SplitString(char *buf[], const char *str, const char *delimiter);
void ReadInputDataInfo(int *student_num, int *subject_num);
void ReadInputData(human *hito, int student_num, int subject_num);
void GetHumanAverage(human *hito, human *ave, int student_num, int subject_num);
void GetSubjectAverage(human *hito, human *ave, int student_num, int subject_num);
void PrintData(human *hito, human ave, int student_num, int subject_num);
void swap(human *a, human *b);
void BubbleSort(human *hito, int size);


int main(void){
  int i = 0, mode = 0;
  human averageman;
  human *classmates;
  int subject_num = 0;
  int student_num = 0;

  printf("バブルソートを行うプログラムです．\n");
  while(1){
    printf("データを入力する…[1]\n乱数を発生させる…[2]\n外部ファイルを読み込む…[3]\n");
    mode = Kakunin();
    if(mode == 0){
      printf("入力エラーです．\n");
    }else if(mode == 1 || mode == 2){
      InputDataSetting(&student_num, &subject_num);
      break;
    }else if(mode == 3){
      ReadInputDataInfo(&student_num, &subject_num);
      break;
    }else{
      continue;
    }
  }

  /* Get Memory */
  classmates = malloc(sizeof(human) * student_num);
  for(i=0; i<student_num; i++){
    classmates[i].CL = malloc(sizeof(subject) * subject_num);
  }
  averageman.CL = malloc(sizeof(subject) * subject_num);

  switch(mode){
  case 1:			/* manual input */
    InputData(classmates, student_num, subject_num);
    break;
  case 2:			/* randam input */
    InputDataRandom(classmates, student_num, subject_num);
    break;
  case 3:			/* external datafile input */
    ReadInputData(classmates, student_num, subject_num);
    break;
  default:
    printf("error\n");
    break;
  }

  GetHumanAverage(classmates, &averageman, student_num, subject_num);
  GetSubjectAverage(classmates, &averageman, student_num, subject_num);
  PrintData(classmates, averageman, student_num, subject_num);

  printf("----------------------Sorted!!!!-------------------------\n");

  BubbleSort(classmates, student_num);
  PrintData(classmates, averageman, student_num, subject_num);

  /* Release memory */
  for(i=0; i<student_num; i++){
    free(classmates[i].CL);
  }
  free(classmates);

  return 0;
}

/*++++++++++++++++++++++++++++++++++++++++++++++*/
/*    GetNSChar...Get Next Non-Space Character  */
/*    非空白類文字を1文字読み込む               */
/*    引数 : なし                               */
/*    返り値 : 得られた非空白類文字をint型で    */
/*++++++++++++++++++++++++++++++++++++++++++++++*/
int GetNSChar(void)
{
  int ch;
  while(isspace(ch = getchar()) && ch != EOF)
    ;
  return ch;
}
/*++++++++++++++++++++++++++++++++++++++++++++++*/
/*    Kakunin...確認                            */
/*    引数 : なし                               */
/*    返り値 : 1...1                            */
/*             2...2                            */
/*             3...3                            */
/*             others...0                      */
/*++++++++++++++++++++++++++++++++++++++++++++++*/
int Kakunin(void)
{
  int ch;
  do{
    ch = GetNSChar();
    if(ch == '1')
      return 1;
    if(ch == '2')
      return 2;
    if(ch == '3')
      return 3;
  }while(ch != EOF);
  return 0;
}

int FlagCheck(char flag)
{
  if(flag == true){
    return 1;
  }else{
    return -1;
  }
}


char InputDataCheck(double point){
    if( point < 0 || point > 100){
      printf("入力エラーです。点数=%lf\n", point);
      return false;
    }else{
      return true;
    }
}

void InputDataSetting(int *student_num, int *subject_num){
  int tmp = 0;
  char num[32];
  while(1){
    printf("何教科にしますか："); scanf("%s",num);
    if((tmp = atoi(num)) == 0){
      printf("error\n");
      continue;
    }else{
      *subject_num = tmp;
      printf("何人にしますか："); scanf("%s",num);
      if((tmp = atoi(num)) == 0){
	printf("error\n");
	continue;
      }else{
	*student_num = tmp;
	break;
      }
    }
  }
}

void InputData(human *hito, int student_num, int subject_num){
  int i,j=0;

  for(i=0; i<student_num; i++){
    hito[i].num = i+1;
    printf("%d人目\n",i+1);
    for(j=0; j<subject_num; j++){
      hito[i].CL[j].point = 0;
      printf("%d科目の点数：", j+1); scanf("%lf", &hito[i].CL[j].point);
      if(InputDataCheck(hito[i].CL[j].point) != true){
        j--;
        continue;
      }
    }
  }
}

void InputDataRandom(human *hito, int student_num, int subject_num){
  int i,j=0;
  srand((unsigned)time(NULL));
  for(i=0; i<student_num; i++){
    hito[i].num = i+1;
    for(j=0; j<subject_num; j++){
      hito[i].CL[j].point = rand()%100+1;
    }
  }
}

int SplitString(char *buf[], const char *str, const char *delimiter)
{
  int i = 0;
  int len = strlen(str);
  char *before, *temp;
  before = (char*)malloc(len + 1);
  strcpy(before, str);
  temp = strtok(before, delimiter);
  if(temp == NULL){
    free(before);
    return 0;
  }else{
    strcpy(buf[0], temp);
    for(i = 1; i < len; i++){
      temp = strtok(NULL, delimiter);
      if(temp != NULL){
	strcpy(buf[i], temp);
      }else{
	break;
      }
    }
  }
  free(before);
  return i;
}

void ReadInputDataInfo(int *student_num, int *subject_num){
  FILE *fp;
  int i, ret = 0;
  char tmp[256];
  char *data[100];

  *student_num = 0;
  *subject_num = 0;

  fp = fopen(filename,"r");
  if(fp == NULL){
    printf("open fail\n");
    exit(1);
  }

  for(i = 0; i<100; i++){
    data[i] = (char *)malloc(256);
  }

  while(fgets( tmp, 255, fp) != NULL){
    ret = SplitString(data, tmp, delimiter);
    *student_num = *student_num +1;
  }
  *subject_num = ret-1;
  printf("student_num = %d, subject_num = %d\n", *student_num, *subject_num);

  for(i = 0; i<100; i++){
    free( data[i]);
  }
}

void ReadInputData(human *hito, int student_num, int subject_num){
  FILE *fp;
  int i, j, ret = 0;
  char tmp[256];
  char *data[100];
  fp = fopen(filename,"r");
  if(fp == NULL){
    printf("open fail\n");
    exit(1);
  }

  for(i = 0; i<100; i++){
    data[i] = (char *)malloc(256);
  }
  for(i=0; i<student_num; i++){
    fgets( tmp, 255, fp);
    ret = SplitString(data, tmp, delimiter);
    hito[i].num = i+1;
    for(j=0; j<ret-1; j++){
      printf("i=%d,j=%d  ",i,j);
      hito[i].CL[j].point = atof(data[j]);
    }
  }

  for(i = 0; i<100; i++){
    free(data[i]);
  }

}

void GetHumanAverage(human *hito, human *ave, int student_num, int subject_num){
  int i,j = 0;
  ave->sum = 0;
  for(i=0; i<student_num; i++){
    hito[i].sum = 0;
    for(j=0; j<subject_num; j++){
     hito[i].sum += hito[i].CL[j].point;
    }
    hito[i].ave = hito[i].sum / (double)subject_num;
    ave->sum += hito[i].ave;
  }
  ave->ave = ave->sum / (double)student_num;
}

void GetSubjectAverage(human *hito, human *ave, int student_num, int subject_num){
  int i,j = 0;
  int sum = 0;
  for(j=0; j<subject_num; j++){
    sum = 0;
    for(i=0; i<student_num; i++){
      sum += hito[i].CL[j].point;
    }
    ave->CL[j].point = sum / (double)student_num;
  }
}

void PrintData(human *hito, human ave, int student_num, int subject_num){
  int i, j = 0;
  for(i=0; i<subject_num; i++){
    printf("------------");
  }
  printf("\n");
  printf("\t");
  for(j=0; j<subject_num; j++){
    printf("%d科目目\t", j+1);
  }
  printf("| 平均\n");
  for(i=0; i<subject_num; i++){
    printf("------------");
  }
  printf("\n");
  for(i=0; i<student_num; i++){
    printf("%d人目\t：\t",hito[i].num);
    for(j=0; j<subject_num; j++){
      printf("%5.1lf\t", hito[i].CL[j].point);
    }
    printf("|%5.1lf\n", hito[i].ave);
  }
  for(i=0;i<subject_num; i++){
    printf("------------");
  }
  printf("\n");
  printf("平均\t：\t");
  for(j=0; j<subject_num; j++){
    printf("%5.1lf\t", ave.CL[j].point);
  }
  printf("\n");
  for(i=0;i<subject_num; i++){
    printf("------------");
  }
  printf("\n");
}

void swap(human *a, human *b){
  human tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void BubbleSort(human *hito, int size){
  int i,j = 0;
  for(i=0; i<size; i++){
    for(j=size-1; j>i; j--){
      if(hito[j-1].ave > hito[j].ave){
	swap(&hito[j-1],&hito[j]);
      }
    }
  }
}

