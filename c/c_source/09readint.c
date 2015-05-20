#include <stdio.h>

int readint(void){
  int num = 0;
  scanf("%i", &num );
  return num;
}

void myscanf(int *pnum){
  int num = 0;

  printf("[myscanf] input number\n");
  scanf("%i", &num);
  *pnum = num;
  return;
}

int main(void){
  int num1 = 0;
  int num2 = 0;
  printf("[readint] input number\n");
  num1 = readint();
  myscanf(&num2);
  printf("num1 = %d ,  num2 = %d\n", num1, num2);

  return 0;
}
