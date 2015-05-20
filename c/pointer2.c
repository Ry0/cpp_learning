#include <stdio.h>

int swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main(void){
	int num1;
	int num2;

	printf("一方の数字を入力\n");
	scanf("%d", &num1);
	printf("num1=%d\n", num1);

	printf("他方の数字を入力\n");
	scanf("%d", &num2);
	printf("num2=%d\n", num2);

	printf("\n");

	swap(&num1, &num2);
	printf("num1=%d\n", num1);
	printf("num2=%d\n", num2);
	return 0;
}