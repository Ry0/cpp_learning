#include <stdio.h>

int main(void){
  float f, c;
  printf("input F\n");
  scanf("%f", &f); //@@@@@@@ 華氏fを読み込む
  printf("F = %f\n", f); //確認表示
  c = (5.0/9.0)*(f-32);
  printf("C = %f\n", c);
  return 0;
}