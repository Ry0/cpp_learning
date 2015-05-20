#include <stdio.h>

int main(void){
  char ch;
  for (ch =33 ; ch < 127 ; ch++ ) {
  printf("'%c' = %i (0x%x)\n", ch, ch, ch);
  }

  return 0;
}