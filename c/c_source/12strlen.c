#include <stdio.h>

int str_length(const char str[]){
  int len = 0;
  while( str[len] != '\0' ){
    len++;
  }
  return (len);
}

int main(void){
  char str[] = "Japan";
  char str2[] = "Netherlands";
  char str3[100];

  printf("length of '%s' = %d\n", str,
                                  str_length(str) ); 

  printf("length of '%s' = %d\n", str2,
                                  str_length(str2) );

  scanf("%s", str3); //read a word from keyboard
  printf("length of '%s' = %d\n", str3,
                                  str_length(str3) );

  return 0;
}