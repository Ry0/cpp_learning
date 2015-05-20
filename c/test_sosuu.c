#include <stdio.h>
int main(void){
	int sosuu;
	int i=0;
	int j=0;
	int so=0;
	int sosu[500];

	sosu[so++] = 2;
	sosu[so++] = 3;
	for (j=5; j<=1000; j+=2){
	for (i=1; i<so; i++){
		sosuu = j % sosu[i];
		if (sosuu == 0){
			break;
		}
	}
	if (so == i){
		sosu[so++] == j;
	}
}
	for (i=0; i<so; i++){
	printf("%d\n", sosu[i]);
}
	return (0);
}