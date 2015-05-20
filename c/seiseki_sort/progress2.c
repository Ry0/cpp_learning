
#include <stdio.h>
#include <time.h>

void clocktime(){
	clock_t t;
	t = clock() + CLOCKS_PER_SEC/20;
	while(t>clock());
}

int main(void){
	int i,j;
	int progress;
	int grogress_count;
	int percent;
	int times=231;

	//setbuf(stdout,NULL);
	grogress_count = times/20;

	for(i=0;i<times;i++){
		clocktime();
		progress = i%(times/20);
		if(progress==grogress_count-1){
			for(j=1;j<=i/(grogress_count)+1;j++){
				printf("■");
			}
			for(j=1;j<=20-(i/(grogress_count)+1);j++){
				printf("□");
			}
			percent = (float)i/times * 100;
			printf("%4d %%",percent);
		}
		fflush(stdout);
		printf("\r");
	}

	for(j=0;j<20;j++){
		printf("■");
	}
	printf("100 %%\n");
	printf("\x1b[2B");

		return 0;
	}

