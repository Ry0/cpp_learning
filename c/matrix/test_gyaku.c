#include <stdio.h>

int main(void){

double mat[3][3];
double E[3][3]={{1,0,0},{0,1,0},{0,0,1}};
double buf;
int i,j,k;
float det=0;

while(1){
for(i=0; i<3; i++){
  for(j=0; j<3; j++){
    printf("%d行、%d列の数字を入力\n",i+1 ,j+1);
    scanf("%lf", &mat[i][j]);
  }
  printf("\n");
}

  det = mat[0][0]*mat[1][1]*mat[2][2]+mat[0][1]*mat[1][2]*mat[2][0]+mat[0][2]*mat[2][1]*mat[1][0]-mat[0][2]*mat[1][1]*mat[2][0]-mat[1][2]*mat[2][1]*mat[0][0]-mat[2][2]*mat[1][0]*mat[0][1];

  if(det != 0){
    printf("det = %lf(detは0でない)より逆行列は存在する。\n",det);
    break;
  }else{
    printf("逆行列は存在しません。打ち直し。\n");
  }
}

//掃き出し法
for(i=0; i<3; i++){
  buf = mat[i][i];
  if(buf==0){
    printf("error\n");
    break;
  }
  for(j=0; j<3; j++){
    mat[i][j] = mat[i][j] / buf;
    E[i][j] = E[i][j] / buf;
  }
  for(j=0; j<3; j++){
    if(i!=j){
      buf = mat[j][i];
      for(k=0;k<3;++k){
      mat[j][k] = mat[j][k] - mat[i][k]*buf;
      E[j][k] = E[j][k] - E[i][k]*buf;
      }
    }
  }
}
//逆行列を出力
for(i=0;i<3;i++){
  for(j=0;j<3;j++){
    printf("%lf ",E[i][j]);
  }
  printf("\n");
}

return 0;
}
