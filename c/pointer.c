#include <stdio.h>

int hiroko(int *height){
	if(*height<180){
		*height = 180;
	}
	return *height;
}

int main(void){
	int ryodo=145;

	hiroko(&ryodo);
	printf("%d\n", ryodo);

return 0;
}
