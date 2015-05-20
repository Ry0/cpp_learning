#include <stdio.h>

int main(void){
	float f,c;

	printf("摂氏を入力[℃]\n");
	scanf("%f", &c);

	f = 1.8*c + 32.0;
	printf("摂氏から華氏に変換された値は%.2f\n[°F]である\n", f);

	return 0;
}