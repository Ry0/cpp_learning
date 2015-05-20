#include <stdio.h>
#include <string.h>

void swap(int *a, int *b){
  int t;
  t = *a;
  *a = *b;
  *b = t;
}

void swaps(char a[], char b[]){
	char temp[256];

	strcpy(temp, a);
	strcpy(a, b);
	strcpy(b, temp);
}

void sort(int data[], char name[][20], int n){
	int i,j;
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			if (data[i]>data[j]){
				swap(&data[i], &data[j]);
				swaps(name[i], name[j]);
			}
		}
	}
}

int main(void){
	int i,n;
	int num[100];
	char name[100][20];

	printf("何人？\n");
	scanf("%d", &n);

	for(i=0; i<n; i++){
			printf("%d番目の人の名前\n",i+1);
			scanf("%s", name[i]);
			printf("%d番目の学籍番号\n",i+1);
			scanf("%d", &num[i]);
	}


	sort(num, name, n);

	for(i=0; i<n; i++){
		printf("%d: %-8s%4d\n", i+1, name[i], num[i]);
	}
}
