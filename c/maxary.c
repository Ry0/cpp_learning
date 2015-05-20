#include <stdio.h>

int max(int a[], int b){
  int max = a[0];
  int i;
  for(i=0; i<b; i++){
    if(max<a[i]){
      max = a[i];
    }
  }
    return (max);
  }

int main(void){
  int ary[5];
  int i=0,m=0;

  for(i=0; i<5; i++){
    printf("%d番目の数字を入力\n", i+1);
    scanf("%d", &ary[i]);
  }
  m = max(ary, 5);
  for(i=0; i<5; i++){
    printf("%d ", ary[i]);
  }
  printf("\n");
  printf("max = %d\n", m);
  return 0;
}
