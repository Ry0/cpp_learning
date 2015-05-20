#include <stdio.h>

int power(int n, int k){
  if (k==0) return 1;
  return n*power(n,k-1);
}

void makeary(int n, int fd[], int mx[], int a[]){
  int i;
  for(i=0;i<20;i++){
    a[i] = (n+mx[i]) / fd[i] % 3;
  }
}

void print(int a[], int n){
  int i;
  for(i=0 ; i < n ; i++) printf("%i ", a[i]);
  printf("\n");
}
int main(void){
  int fundo[20];
  int max[20];
  int a[20];
  int i;
  int num;
  int sum=0;

  for(i=0;i<20;i++){
     max[i] = sum;
     fundo[i] = power(3,i);
     sum = sum + fundo[i];
  }

  for(i=0;i<20;i++){
     printf("(確認用) fundo[%i] = %i  max[%i] = %i\n", i, fundo[i], i, max[i]);
  }

  printf("input NUM\n");
  scanf("%i",&num);

  makeary( num , fundo , max , a);
  printf("(確認用) a: "); print(a, 20);

  for(i=0;i<20;i++){
    if (a[i] == 2) printf("%i ", fundo[i]);
  }
  printf("NUM = ");
  for(i=0;i<20;i++){
    if (a[i] == 1) printf("%i ", fundo[i]);
  }
  printf("\n");

  return 0;
}