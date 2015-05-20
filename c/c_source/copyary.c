#include <stdio.h>

 void copyary(int src[], int dst[], int n){
  int i;
  for( i = 0; i < n ; i++ )
  dst[i]=src[i];
 }

  void printary(int a[], int n){
  int i;
  for( i = 0; i < n ; i++ ){
  printf("&a[%i] = %i\n", i, a[i] );}
 }

int main(void){ 
  int orig[7] = { 84, 79, 66, 65, 84, 65, 0 };
  int cpy[7];

  printary( cpy, 7 );

  copyary(orig, cpy, 7);

  printary( cpy, 7 );

  return 0;
}