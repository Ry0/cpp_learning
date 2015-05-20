#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
  int t;
  t = *a;
  *a = *b;
  *b = t;
}

void sort(int *a, int size){
  int i,j;
  for(i=0; i<size; i++){
    for(j=i+1; j<size; j++){
       if (a[i]<a[j]){
          swap(&a[i], &a[j]);
       }
    }
  }
}

int main(void){
  int i;
  int j;
  int *a;
  int n;

  printf("数字の個数を入力\n");
  scanf("%d", &n);

  a = (int *)malloc(sizeof(int) * n);
  if (a == NULL){
    exit(0);
  }

  for (j=0; j<n; j++) {
    printf("%d番目の数字を入力", j+1);
    scanf("%d", &a[j]);
  }
  free(a);

  sort(a, n);
  for (i=0; i<n; i++){
  printf("%d ", a[i]);
}
  printf("\n");
  return 0;
}
