#include <stdio.h>

int factorial(int n){
  int i;
  int f = 1;
  for(i=1; i<=n; i++){
  f =i*f;
  }
  return f;
}

int main(void){ 
  printf("7! = %i\n", factorial(7) ); 
  printf("12! = %i\n", factorial(12) ); 
  return 0;
}
