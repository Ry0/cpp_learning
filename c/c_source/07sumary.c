#include <stdio.h>

int sumary(int a[], int n){
   int  i, sum = 0 ;
   for ( i = 0; i<n; i++)  sum = sum + a[ i ];
   return   sum;
}

int main(void){
  int ary[11] = { 3, 5, 2, 4, 6, 8, 2, 7, 3, 1, 9 };
  int retval;
  retval = sumary(ary, 11);
  printf("sum of ary = %i\n", retval);

  return 0;
}