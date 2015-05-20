#include <stdio.h>

unsigned long int factorial(int x){
	if (x == 0) {
		return 1;
	}else{
		return x * factorial(x - 1);
    }
}

int main(void){
	int num;

	printf("n!を計算\n");
	scanf("%d",&num);

	printf("%d! = %ld\n", num, factorial(num));

}
