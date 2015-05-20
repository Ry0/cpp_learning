#include <stdio.h>
int main(void){
	int i,j;
	int n;

	printf("何段にしますか？\n");
	scanf("%d",&n);
	for (i = 1; i <= n; i++){
		for (j = 1; j <= (n-i); j++){
			printf(" ");
		}
		for (j = 1; j <= (2*i-1); j++){
			printf("*");
		}
		printf("\n");
	}
return 0;
}