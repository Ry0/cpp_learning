#include <stdio.h>

int main(void){
   int prime[1001];
   int n = 2, i, isprime;
   int indexp = 1;
   int input;

   while(indexp < 1001){
      isprime = 1;
      for(i=2; i<n; i++){
         if (n%i==0) {
            isprime = 0;
            break;
         }
      }
      if (isprime==1){
         prime[indexp] = n;
         indexp++;
      }
      n++;
   }
   while(1==1){
      printf("n番目の素数を調べます。nを入力してください。\n");
      printf("(1<=n<=1000) 0で終了\n");
      scanf("%i",&input);
      if (input==0) break; 
      if (input<1 || 1000<input) {
         printf("範囲外です。1<=n<=1000でnを入力してください。\n");
      } else {
         printf("%i番目の素数は、%i です。\n",input , prime[input]);
      }
   }
   return 0;
}