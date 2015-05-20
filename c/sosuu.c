#include <stdio.h>
int sosuuuu(int no){
	int sosuu;
	int i,j;
	int so=0;
	int sosu[10000];

	sosu[so++] = 2;
	sosu[so++] = 3;
	if (no%2 == 0){
		break;
	}else{
	for (i = 1; i < so; i++){
		sosuu = no % sosu[i];
		if (sosuu == 0){
			break;
		}
	}
	if (so == i){
		sosu[so++] == no;
	}
}
	return (sosuu);
	}

int main(void){
	int num_end;
	int num2;
	FILE *fp;

	// if((fp = fopen("sosuu.dat","w"))== NULL){
	// printf("\aファイルをオープンできません。\n");
	// }
	while(1){
	printf("調べる数字の始まりを入力\n");
	scanf("%d",&num2);
	printf("調べる数字の終わりを入力\n");
	scanf("%d",&num_end);
	if(num_end <= num2){
		printf("エラー\n打ち直し\n");
	}else{
		break;
	}
//}

// 	while(num2 <= num_end){
// 	if(num2 == 2){
// 		printf("%dは素数\nよって%dをファイルに書き込み\n",num2,num2);
// 		fprintf(fp,"%d\n",num2);
// 	}else{
// 	// printf("\n数字を入力\n");
// 	// scanf("%d", &num2);
// 	sosuuuu(num2);
// 	if(sosuuuu(num2) == 0){
// 		printf("%dは素数ではない\n",num2);
// 	}else{
// 		printf("%dは素数\nよって%dをファイルに書き込み\n",num2,num2);
// 		fprintf(fp,"%d\n",num2);
// 	}
// }
// 	num2++;
// }

	for (i = 0; i < count; ++i)
	{
		/* code */
	}
	return 0;
}