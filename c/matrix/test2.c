#include <stdio.h>
#include <stdlib.h>

int main(void){
	int **matrix_A;
	int **matrix_B;
	int i,j,n;
	int **mat_sum;
	int **mat_sub;

	printf("n×n行列にするか\n");
	scanf("%d", &n);

	matrix_A = malloc(sizeof(int *) * n);
	for (i=0;i<n;i++){
		matrix_A[i] = malloc(sizeof(int) * n);
	}

	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			printf("行列の第%d行、第%d列を入力\n", i+1, j+1);
			scanf("%d", &matrix_A[i][j]);
		}
		printf("\n");
	}
	free(matrix_A);

	printf("行列A=\n");
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			printf("%d ", matrix_A[i][j]);
		}
		printf("\n");
	}

	matrix_B = malloc(sizeof(int *) * n);
	for (i=0;i<n;i++){
		matrix_B[i] = malloc(sizeof(int) * n);
	}

	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			printf("行列の第%d行、第%d列を入力\n", i+1, j+1);
			scanf("%d", &matrix_B[i][j]);
		}
		printf("\n");
	}
	free(matrix_B);

	printf("行列B=\n");
	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			printf("%d ", matrix_B[i][j]);
		}
		printf("\n");
	}

	mat_sum = malloc(sizeof(int *) * n);
	for (i=0;i<n;i++){
		mat_sum[i] = malloc(sizeof(int) * n);
	}
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			mat_sum[i][j] = matrix_A[i][j] + matrix_B[i][j];
		}
	}
	free(mat_sum);

	mat_sub = malloc(sizeof(int *) * n);
	for (i=0;i<n;i++){
		mat_sub[i] = malloc(sizeof(int) * n);
	}
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			mat_sub[i][j] = matrix_A[i][j] - matrix_B[i][j];
		}
	}
	free(mat_sub);

	printf("mat_sum=\n");
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			printf("%d ", mat_sum[i][j]);
		}
		printf("\n");
	}

	printf("mat_sub=\n");
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			printf("%d ", mat_sub[i][j]);
		}
		printf("\n");
	}

	printf("行列Aと行列Bの和(A+B)=\n");
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			printf("%d ", mat_sum[i][j]);
		}
		printf("\n");
	}

	printf("行列Aと行列Bの差(A-B)=\n");
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			printf("%d ", mat_sub[i][j]);
		}
		printf("\n");
	}

	return 0;
}
