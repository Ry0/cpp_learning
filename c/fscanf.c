#include <stdio.h>

int main(void){
	FILE *fp;
	int ninzu = 0;
	char name[20];
	double height, weight;
	double h_sum = 0;
	double w_sum = 0;

	if((fp = fopen("data.dat", "r")) == NULL){
		printf("ファイルをオープンできません\n");
	}else{
		while(fscanf(fp, "%s %lf %lf", name, &height, &weight)==3){
			printf("%-10s %5.1f %5.1f\n", name, height, weight);
			ninzu++;
			h_sum += height;
			w_sum +=weight;
		}
		printf("-----------------------------\n");
		printf("平均  %5.1f %5.1f\n", h_sum/ninzu, w_sum/ninzu);
		fclose(fp);
	}
	return 0;
}