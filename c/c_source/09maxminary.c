#include <stdio.h>

void maxminary(int a[], int n, int *pmax, int *pmin){
  int max = 0;
  int min = 99999;
  int i;
  for ( i = 0; i<n; i++){
   if(max<a[i])
   max=a[i];
   else if(a[i]<min)
   min=a[i];
 }
  *pmax = max;
  *pmin = min;

  return;
}

int main(void){
  int ary[11] = { 3, 5, 2, 4, 6, 8, 2, 7, 3, 1, -2 };
  int saidai, saisho;
  maxminary(ary, 11, &saidai, &saisho);

  printf("max of ary = %i\n", saidai);
  printf("min of ary = %i\n", saisho);

  return 0;
}