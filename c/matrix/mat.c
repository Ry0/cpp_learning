#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int define_mat(int **matrix, int n){
	matrix = malloc(sizeof(int *) * n);
	for (i=0;i<n;i++) {
		matrix_A[i] = malloc(sizeof(int) * n);
	}

	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			printf("行列の第%d行、第%d列を入力\n", i+1, j+1);
			scanf("%d", &matrix_A[i][j]);
		}
		printf("\n");
	}

	free(matrix);
	return matrix;
}

int mat_sum(int **a, int **b, int num){
	int **sum;
	int i,j;
	for(i=0; i<num; i++){
		for(j=0; j<num; j++){
			sum[i][j] = a[i][j] + b[i][j];
		}
	}
	return sum
}


int main(void){
	int **matrix_A;
	int **matrix_B;
	int i,j,n;
	int deter;

	// printf("n×n行列にするか\n");
	// scanf("%d", &n);

	// matrix_A = malloc(sizeof(int *) * n);
	// for (i=0;i<n;i++) {
	// 	matrix_A[i] = malloc(sizeof(int) * n);
	// }

	// for (i=0;i<n;i++) {
	// 	for (j=0;j<n;j++) {
	// 		printf("行列の第%d行、第%d列を入力\n", i+1, j+1);
	// 		scanf("%d", &matrix_A[i][j]);
	// 	}
	// 	printf("\n");
	// }

	// free(matrix_A);

	// for (i=0;i<n;i++) {
	// 	for (j=0;j<n;j++) {
	// 		printf("%d ", matrix_A[i][j]);
	// 	}
	// 	printf("\n");
	// }


	mat_sum()



}
