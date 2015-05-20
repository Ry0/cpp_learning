#include <stdio.h>

void revstr(char r[], const char str[]){
  int p=0;
  int len=0;
  while( str[len] != 0 ){
    len++;
  }
  for( p = 0; p<len; p++){
   r[p]= str[len-1-p];
  }
   r[len]=0;
  }

int main(void){
  char str[] = "abcdef";
  char res[10];
  printf("str = %s\n", str);
  revstr(res,str);
  printf("res = %s\n", res);
  return 0;
}