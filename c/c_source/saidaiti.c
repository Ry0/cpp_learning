#include <stdio.h>

int maxof2(int a, int b){
 if (b<=a){
  return a;
 }
 else{
  return b;
  }
 }

int maxof3(int a, int b, int c){
 return maxof2(a,maxof2(b,c));
 }

int maxof4(int a, int b, int c, int d){
 return maxof2(a,maxof2(b,maxof2(c,d)));
 }

int main(void){
  printf("max of 5,3 = %i\n", maxof2(5,3) );
  printf("max of 6,4,8 = %i\n", maxof3(6,4,8) );
  printf("max of 15,13,11,9 = %i\n", maxof4(15,13,11,9) );
  return 0;
}
