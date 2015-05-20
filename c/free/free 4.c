#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 9

int main(void){
  int i,j;
  int x,y;
  int input[SIZE][SIZE];
  double output[SIZE][SIZE];
  int sum;
  int cnt=0;

  srand((unsigned) time(NULL));

  //乱数で生成されたデータを表示、コピー
  printf("~元データ~\n");
  for(y=0; y<SIZE; y++){
    for(x=0; x<SIZE; x++){
      input[x][y] = rand()%9+1;
      output[x][y] = input[x][y];
      printf("%2d", input[x][y]);
    }
    printf("\n");
  }
  printf("\n");


  //平均の計算
  for(i=1;i<SIZE-1;i++){
    //左端の1ブロック分は普通に計算
    for(y=i-1;y<=i+1;y++){
      for(x=0;x<=2;x++){
        sum += input[x][y];
        cnt++;
      }
    }
    output[1][i] = (double)sum/9;

    //左端の1ブロック分を初項として２ブロック目移行は計算を効率化
    for(j=2;j<SIZE-1;j++){
      for(y=i-1;y<=i+1;y++){
        sum += input[j+1][y];//注目点のx座標がひとつ進んだ部分の配列データ３つ分(y成分３つ)を足し算
        cnt++;
        sum -= input[j-2][y];//必要ではなくなった配列３つ分(y成分３つ)の引き算
        cnt++;
      }
      output[j][i] = (double)sum/9;
    }

    sum = 0;
  }


  //計算結果の表示
  printf("~平均計算後~\n");
  for(y=0;y<SIZE;y++){
    for(x=0;x<SIZE;x++){
      printf("%5.2lf", output[x][y]);
    }
    printf("\n");
  }
  printf("\n");


  printf("計算回数 %d\n", cnt);

  return 0;
}


