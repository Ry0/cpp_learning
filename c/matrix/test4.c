#include <stdio.h>
#include <stdlib.h>
#define N 2

int main(void){
	int matrix_A[N][N];
	int matrix_B[N][N];
	int i,j,n;
	int sum[N][N];
	int sub[N][N];



	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			printf("行列の第%d行、第%d列を入力\n", i+1, j+1);
			scanf("%d", &matrix_A[i][j]);
		}
		printf("\n");
	}

	printf("行列A=\n");
	for (i=0;i<N;i++){
		for (j=0;j<N;j++){
			printf("%d ", matrix_A[i][j]);
		}
		printf("\n");
	}

	for (i=0;i<N;i++){
		for (j=0;j<N;j++){
			printf("行列の第%d行、第%d列を入力\n", i+1, j+1);
			scanf("%d", &matrix_B[i][j]);
		}
		printf("\n");
	}

	printf("行列B=\n");
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			printf("%d ", matrix_B[i][j]);
		}
		printf("\n");
	}

	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			sum[i][j] = matrix_A[i][j] + matrix_B[i][j];
		}
	}
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			sub[i][j] = matrix_A[i][j] - matrix_B[i][j];
		}
	}

	printf("行列Aと行列Bの和(A+B=)\n");
	for (i=0;i<N;i++){
		for (j=0;j<N;j++){
			printf("%d ", sum[i][j]);
		}
		printf("\n");
	}

	printf("行列Aと行列Bの差(A-B=)\n");
	for (i=0;i<N;i++){
		for (j=0;j<N;j++){
			printf("%d ", sub[i][j]);
		}
		printf("\n");
	}

	return 0;
}
