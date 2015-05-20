#include <stdio.h>
int main(void){
//int moji = 'A'; //65; // 4byteの整数
  char moji = 'A';  //65　// 1byteの整数(0~25)
  printf("%i = %c\n", moji, moji);
  putchar(0x44);
  return 0;
}
