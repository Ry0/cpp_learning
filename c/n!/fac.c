#include <stdio.h>

int main(void){
	int num;

	printf("n!を計算\n");
	scanf("%d",&num);

	printf("%d! = %ld\n", num, factorial(num));

}
