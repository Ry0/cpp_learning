#include <stdio.h>

void swap(char *a, char *b){
  char t;
  t = *a;
  *a = *b;
  *b = t;
}

void sort(char a[], int size){
  int i,j;
  for(i=0; i<size; i++){
    for(j=i+1; j<size; j++){
       if (a[i]>a[j]){
          swap(&a[i], &a[j]);
       }
    }
  }
}

int main(void){
  char a[6];
  int i;

  for (i=0; i<6; i++){
    printf("%d番目の数字を入力\n", i);
    scanf("%s", &a[i]);
  }

  printf("%s\n", a);
  sort(&a[0], 5);
  printf("%s\n", a);

  return 0;
}
