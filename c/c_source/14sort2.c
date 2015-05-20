#include <stdio.h>

void swap(char *a, char *b){
  char t;
  t = *a;
  *a = *b;
  *b = t;
}
void mysort(char a[], int size){
  int i,j;
  int minval ,minidx;
  for(i=0;i < size;i++){
   minval = a[i];
   minidx = i;
   for(j=i+1; j<size; j++){
       if (minval > a[j]){
        minval = a[j];
        minidx = j; 
       }
    }
     swap(&a[i], &a[minidx]);
  }
}

int main(void){
  char a[6] = {67,65,69,66,68, 0};

  printf("%s\n", a);
  mysort(&a[0], 5);
  printf("%s\n", a);

  return 0;
}
