#include <stdio.h>

int main(void){
	int i,j,k;
	int sum=0;

		printf("iからkまでの和を求める\n");
	while(1){

		while(1){
			printf("iを入力\n");
			scanf("%d", &i);
			if(i>0){
				break;
			}else{
				printf("iが不正な値です。打ち直してください。\n");
			}
		}

		while(1){
			printf("kを入力\n");
			scanf("%d", &k);
			if(k>0){
				break;
			}else{
				printf("kが不正な値です。打ち直してください。\n");
			}
		}

		if(i<k){
			break;
		}else{
			printf("iがkよりも大きいです。打ち直してください。\n");
		}
	}

	for(j=i; j<=k; j++){
		sum = sum + j;
	}

	printf("iからkまでの和は%dです\n", sum);

	return 0;
}




