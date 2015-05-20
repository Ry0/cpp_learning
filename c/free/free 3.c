#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define X_SIZE 15
#define Y_SIZE 15

int main(void)
{
  int i,j;
  int k=0;
  int x,y;
  int a[X_SIZE][Y_SIZE];
  double b[X_SIZE][Y_SIZE];
  double x_sum[X_SIZE][Y_SIZE]={0};
  double y_sum[X_SIZE];
  int counter=0;

  srand((unsigned) time(NULL));

  for(i=0; i<X_SIZE; i++){
    for(j=0; j<Y_SIZE; j++){
      a[i][j] = rand()%100+1;
      b[i][j] = a[i][j];
      printf("%4d", a[i][j]);
    }
    printf("\n");
  }

  // for(i=0; i<X_SIZE; i++){
  //   for(j=0; j<Y_SIZE; j++){
  //     a[i][j] = k;
  //     b[i][j] = a[i][j];
  //     k++;
  //     printf("%4d", a[i][j]);
  //   }
  //   printf("\n");
  // }

  printf("\n");

  for(j=1; j<Y_SIZE-1; j++){
    for(k=0; k<X_SIZE; k++){
      y_sum[k] = 0;
    }
    for(i=1; i<X_SIZE-1; i++){
      if(i==1){
        for(x=-1; x<=1; x++){
          y_sum[i+x] = a[i+x][j-1] + a[i+x][j] + a[i+x][j+1];
          counter++;
          counter++;
          counter++;
        }
        x_sum[i][j] = y_sum[i-1] + y_sum[i] + y_sum[i+1];
        counter++;
        counter++;
        counter++;
        b[i][j] = x_sum[i][j]/9;
    }else{
      for(x=-1; x<=1; x++){
        y_sum[i+x] = a[i+x][j-1] + a[i+x][j] + a[i+x][j+1];
        counter++;
        counter++;
        counter++;
      }
      x_sum[i][j] = x_sum[i-1][j] - y_sum[i-2] + y_sum[i+1];
        counter++;
        counter++;
        counter++;
      b[i][j] = x_sum[i][j]/9;
    }
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


