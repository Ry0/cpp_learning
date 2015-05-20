#include <stdio.h>
int main(void){
	float i,j;
	float BMI;

printf("体重を入力[kg]\n");
scanf("%f",&i);
printf("身長を入力[ｍ]\n");
scanf("%f",&j);
BMI = i/(j*j);
printf("%f\n", BMI);
if (BMI>=24.9){
	printf("運動を始めてください\n");
}else if (BMI<=18.5){
	printf("食欲増進運動を始めましょう\n");
}else{
	printf("今の体重を保ちましょう\n");
}

return 0;
}