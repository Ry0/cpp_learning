#include <stdio.h>
#include <stdlib.h>

int main(void){
float **matrix=0;
int i, j, n, k;
float buf;
double **E=0;

printf("n×n行列にするか\n");
scanf("%d", &n);

matrix = malloc(sizeof(float *) * n);
for (i=0;i<n;i++) {
	matrix[i] = malloc(sizeof(float) * n);
}

for (i=0;i<n;i++) {
	for (j=0;j<n;j++) {
		printf("行列の第%d行、第%d列を入力\n", i+1, j+1);
		scanf("%f", &matrix[i][j]);
	}
	printf("\n");
}
//free(matrix);

for (i=0;i<n;i++) {
	for (j=0;j<n;j++) {
		printf("%f ", matrix[i][j]);
	}
	printf("\n");
}
	printf("\n");

E = malloc(sizeof(float *) * n);
for (i=0;i<n;i++) {
	E[i] = malloc(sizeof(float) * n);
}

for (i=0;i<n;i++) {
	for (j=0;j<n;j++) {
		if(j==i){
			E[i][j] = 1;
		}else{
			E[i][j] = 0;
		}
	}
}
//free(E);


for (i=0;i<n;i++) {
	for (j=0;j<n;j++) {
		printf("%f ", E[i][j]);
	}
	printf("\n");
}

	printf("\n");


for(i=0; i<n; i++){
	buf = 1/matrix[i][i];
	for(j=0; j<n; j++){
		matrix[i][j] = matrix[i][j] * buf;
		E[i][j] = E[i][j] * buf;
	}
	for(j=0;j<n;j++){
		if(i != j){
			buf = matrix[j][i];
			for(k=0; k<n; k++){
			matrix[j][k] = matrix[j][k] - (matrix[i][k]*buf);
			E[j][k] = E[j][k] - (E[i][k] * buf);
			}
		}
	}
}


for(i=0;i<n;i++){
	for(j=0;j<n;j++){
	printf("%f ",E[i][j]);
	}
	printf("\n");
}
	printf("\n");

return 0;
}