#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
  int i;
  int a[50];
  int max=-99;
  int counter;

  srand((unsigned) time(NULL));

  for(i=0; i<50; i++) {
    a[i]=rand()%100+1;
    printf("a[%d] = %3d\n",i ,a[i]);
  }
  
  for(i=0; i<50; i++){
    if(a[i]>=max){
      max=a[i];
      counter=i;
    }
  }
  printf("最大値は配列a[%d]のときで%dである\n" ,counter ,max);
            
  return 0;
}
