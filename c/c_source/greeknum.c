#include <stdio.h>

int greeknum( char s[] ){
  int pos = 0;
  int sum = 0;
  while( s[pos] != 0 ){
    if(s[pos]=='i'||s[pos]=='I'){
     sum=sum+1;
   }
    if(s[pos]=='v'||s[pos]=='V'){
     sum=sum+5;
   }
    if(s[pos]=='x'||s[pos]=='X'){
     sum=sum+10;
   }
    pos++;
  }
  return sum;
}

int main(void){
  char rn[300];

  printf("input roman num\n");
  scanf("%s", rn);

  printf("数 = %i\n", greeknum(rn) );

  return 0;
}