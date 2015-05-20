#define SOUSU 20 // この 20 を実際のデータの数に書きなおす
#define N 10 // この 10 を 100 に書きなおす

#include <stdio.h>
#include <stdlib.h> // rand()

int ptr=0;
int Buff[100];
int sum=0;

// ■ 改良版
double Calc(int dat)
{
	double ret;
	int i;

	if(ptr <= N-1){
		Buff[ptr]=dat;
		sum += dat;
		ptr++;
		return 0.0;
	}
// 101個目から先のデータ
	sum += (double)(dat - Buff[0]);

	for( i=0; i <= N-2; i++ ) {
		Buff[i] = Buff[i + 1];
	}
	Buff[N - 1] = dat; //最新データ
	ret = (double)sum/N;

return ret;
}


int main(void)
{
	int i, data;
	double average;

	printf("総数%d個のデータの%d個分の移動平均は次の通り\n", SOUSU, N);
	for(i=0; i<SOUSU; i++){
		data = 50 + rand() % 10; // 50～59までの乱数
		printf("[%3d] 乱数：%d\n", i, data);
		average = Calc(data);
		if(average > 0.0){
			printf("%.2f\n", average);
		}
	}
return 0;
}