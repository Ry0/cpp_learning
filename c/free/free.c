#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define X_SIZE 9
#define Y_SIZE 9

int main(void)
{
  int i,j;
  int k=0;
  int x,y;
  int a[X_SIZE][Y_SIZE];
  double b[X_SIZE][Y_SIZE];
  double x_sum,y_sum[3];
  int counter=0;

  // srand((unsigned) time(NULL));

  // for(i=0; i<X_SIZE; i++){
  //   for(j=0; j<Y_SIZE; j++){
  //     a[i][j] = rand()%100+1;
  //     b[i][j] = a[i][j];
  //     printf("%4d", a[i][j]);
  //   }
  //   printf("\n");
  // }

  for(i=0; i<X_SIZE; i++){
    for(j=0; j<Y_SIZE; j++){
      a[i][j] = k;
      b[i][j] = a[i][j];
      k++;
      printf("%4d", a[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  for(i=1; i<X_SIZE-1; i++){
    for(j=1; j<Y_SIZE-1; j++){
      x_sum=0;
      for(x=-1; x<=1; x++){
        y_sum[x+1]=0;
        for(y=-1; y<=1; y++){
          y_sum[x+1] = y_sum[x+1] + a[i+x][j+y];
          counter++;
        }
        x_sum = x_sum + y_sum[x+1];
        counter++;
      }

      b[i][j] = x_sum/9;
    }
  }

  for(i=0; i<X_SIZE; i++){
    for(j=0; j<Y_SIZE; j++){
      printf("%7.2lf", b[i][j]);
    }
    printf("\n");
  }

  printf("計算回数%d\n", counter);

  return 0;
}


