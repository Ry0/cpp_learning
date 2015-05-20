#include <stdio.h>
#include <math.h>

int main(void){
	float height;
	float weight;

	printf("身長を入力(cm)\n");
	scanf("%f", &height);

	weight = 22*pow(height/100, 2);
	printf("身長が%f(cm)の場合の標準体重は%f(kg)です\n", height, weight);
	return 0;
}