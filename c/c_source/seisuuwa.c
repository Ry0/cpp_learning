#include <stdio.h>

int main(void){
  int min, max, sum, num;
  sum = 0;
  printf("min\n");
  scanf("%i", &min);
  printf("max\n");
  scanf("%i", &max);
  num = min;
  while (num <= max){
  sum = sum + num;
  num = num + 1;
  }
  printf("%i から %i までの整数の和は %i\n" ,min, max, sum);
  return 0;
}