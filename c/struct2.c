#include <math.h>
#include <stdio.h>

typedef struct {
	int x;
	int y;
} point;

double kyori(point a, point b){
	int k;

	k = sqrt (pow((a.x-b.x), 2) + pow((a.y-b.y), 2));
	return k;
}

int main(void){
	point p1;
	point p2;

	printf("点1のx座標：");
	scanf("%d", &p1.x);
	printf("点1のy座標：");
	scanf("%d", &p1.y);
	printf("点2のx座標：");
	scanf("%d", &p2.x);
	printf("点2のy座標：");
	scanf("%d", &p2.y);

	printf("2点間の距離 = %.2lf\n", kyori(p1, p2));

	return 0;
}