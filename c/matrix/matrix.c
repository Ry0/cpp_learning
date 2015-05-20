#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int det(int n, int** mat){
	int i,j,retu,sum=0;
	int m=0;
	int ary[n-1][n-1];
	int det_n[n];
	int det(int n, int** mat);

	if (n == 0) {
		return 1;
	}else{
		for(retu=0; retu<n; retu++){
			for(i=0; i<(n-1); i++){
				for(j=0; j<(n-1); j++){
					if(retu<=j){
						ary[i][j] = mat[i+1][j+1];
					}else{
						ary[i][j] = mat[i+1][j];
					}
				}
			}
		// det_n[retu] = pow(-1,retu)*mat[0][retu]*det(n-1, &&ary[n-1][n-1]);

	}
		for(i=0; i<n; i++){
			sum = det_n[i] + sum;
		}
		return sum;
    }
}

int main(void){
int **matrix;
int i, j, n;
int deter;

printf("n×n行列にするか\n");
scanf("%d", &n);

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

for (i=0;i<n;i++) {
	for (j=0;j<n;j++) {
		printf("%d ", matrix[i][j]);
	}
	printf("\n");
}
deter = det(n, matrix);
printf("%d",deter);
return 0;
}