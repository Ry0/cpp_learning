#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void swap(int *a, int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int main(void)
{
  int i,j,k,l;
  int a[50];
  int b[50];

  int counter;

  srand((unsigned) time(NULL));

  for(i=0; i<50; i++) {
    a[i]=rand()%100+1;
    printf("a[%d] = %3d\n",i ,a[i]);
  }
 
  for(i=0; i<50; i++){
    b[i]=i;
  }

  for(i=0; i<50; i++){
    for(j=i+1; j<50; j++){
       if (a[i]<a[j]){
	 k = i;
	 l = j;
	 b[i] = l;
	 b[j] = k;
          swap(&a[i], &a[j]);
       }
    }
  }
  printf("最大値はa[%d]の%dであり、最小値はa[%d]の%dである。\n" ,b[49] ,a[49] ,b[0] ,a[0]);
            
  return 0;
}


