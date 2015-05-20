#include <stdio.h>
int main(void){
  int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
  int num, m, d;
  printf("月日を入力\n");
  scanf("%i",&num);
   m = num / 100;
   d = num % 100;
   if ( (1<=m) && (m<=12) ){
    printf("%i月%i日\n" , m, d);
    printf("%i月の日数は %i 日\n" , m, days[m]);
     if ( (1<=d) && (d<=days[m]) ) {
     printf("OK\n");
     }
    else{
    printf("NG\n");
    }
   }
  else {
  printf("%i月は存在しません\n", m);
  }
  return 0;
}
