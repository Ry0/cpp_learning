#include <stdio.h>
#include <math.h>

int main(void){
  double a, b, c;
  double ans, ans1, ans2;
  double ans_temp1, ans_temp2;
  double D;

  printf("ax^2+bx+c=0の解を求める。\n");

  while(1){

    printf("Input a\n");
    scanf("%lf", &a);

    printf("Input b\n");
    scanf("%lf", &b);

    if(a == 0 && b == 0){
      printf("入力された値はa = 0,b = 0で方程式の解がありません。打ち直して下さい。\n");
    }else{
      break;
    }
  }

  printf("Input c\n");
  scanf("%lf", &c);

  D = b*b - 4*a*c;

  if(a==0){
    ans = -c/b;
    printf("ans = %.3lf\n", ans);

  }else{
    if(D>0){
      ans1 = (-b + sqrt(D))/(2*a);
      ans2 = (-b - sqrt(D))/(2*a);
      printf("Ans = %.3lf, %.3lf\n", ans1, ans2);

    }else if(D==0){
      ans = -b/(2*a);
      printf("Ans = %.3lf\n", ans);

    }else{
      ans_temp1 = -b/(2*a);
      ans_temp2 = sqrt(-D)/(2*a);

      if(ans_temp1==0){
       printf("Ans = %.3lfi, -%.3lfi\n", ans_temp2, ans_temp2);
     }else{
       printf("Ans = %.3lf+%.3lfi, %.3lf-%.3lfi\n", ans_temp1, ans_temp2, ans_temp1, ans_temp2);
     }
   }
 }
}


