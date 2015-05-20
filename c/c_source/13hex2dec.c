#include <stdio.h>
int hex2dec(char c){
  if ('0' <= c && c <= '9'){
     return (c - '0');
  } else if ('a' <= c && c <= 'f'){ 
     return (c - 'a' + 10);
  } else if ('A' <= c && c <= 'F'){
     return (c - 'A' + 10);
  } else {
     return -1;
  }
}


int mystrlen(char s[]){
  int pos = 0;
  while( s[pos] ) pos++;
  return pos;
}

int power(int b, int n){
  if (n <= 0) return 1;
  else return ( b * power(b, n-1) );
}

int main(void){
  char str[100];
  int num;
  int len;
  int i;
  int base = 16;

  printf("16進数の数値(0-9,a-fの並び)を入力\n");
  scanf("%s", str);

  len = mystrlen(str);
  if (len == 1){
    num = hex2dec(str[0]);
  } else if (len == 2){
    num = hex2dec(str[1]) + hex2dec(str[0])*base;
  } else {
    num = 0;
    for(i=0; i<len; i++){ 
      num = num + (hex2dec(str[i]) * power(base, len-i-1));
    }
  }

  printf("0x%s = %d (10進数)\n", str, num);
  
  return 0;
}