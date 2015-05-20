
#include <stdio.h>

void input_sentence( char str[] ){
   char ch;
   int p=0;
   while ( (ch = getchar() ) != 10 ) { //Enterでなければ
      str[p] = ch;
      p++;
   }
   str[p] = 0;
}

int main(void){
  char txt[100];
  printf("input sentence\n");
  input_sentence( txt );
  printf("whole sentence = %s\n", txt );
  return 0;
}

