#include <sys/time.h>
//#include <time.h>
#include <stdio.h>

int main(void){
	char dt;
	struct timeval s, e;

	printf("なんか打て\n");
	gettimeofday(&s, NULL);
	scanf("%s", &dt);

	gettimeofday(&e, NULL);
	printf("time = %lf\n", (e.tv_sec - s.tv_sec) + (e.tv_usec - s.tv_usec)*1.0E-6);
return 0;
}