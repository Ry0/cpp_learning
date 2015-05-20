#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int define_mat(int **matrix, int n){
	int i,j;

	matrix = malloc(sizeof(int *) * n);

	for (i=0;i<n;i++) {
		matrix[i] = malloc(sizeof(int) * n);
	}

	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			printf("行列の第%d行、第%d列を入力\n", i+1, j+1);
			scanf("%d", &matrix[i][j]);
		}
		printf("\n");
	}

	free(matrix);
	return matrix;
}

int main(void){
	int **matrix_A;
	int i,j,n;

	printf("n×n行列にするか\n");
	scanf("%d", &n);

	define_mat(matrix_A, n);

	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			printf("%d ", matrix_A[i][j]);
		}
		printf("\n");
	}
}
