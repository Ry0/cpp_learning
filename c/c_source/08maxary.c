#include <stdio.h>

int maxary(int a[], int n){
  int max = a[0];
  int i;
   for ( i = 0; i<n; i++)
   if(max<a[i])
   max=a[i];
   return   max;
}

int main(void){
  int ary[11] = { 3, 5, 2, 4, 6, 8, 2, 7, 3, 1, -2 };
  int retval;
  retval = maxary(ary, 11);
  printf("max of ary = %i\n", retval); 

  return 0;
}
