#include <stdio.h>

int main(void){
  int year;
  while(1<2){
    printf("誕生年を入力してください. \n");
    scanf("%i", &year);
    if ((1868<=year)&&(year<1912)){
    printf("あなたは明治生まれで，%d 歳です．\n", 2012-year);
      break;
    } else if ((1912<=year)&&(year<1926)){
    printf("あなたは大正生まれで，%d 歳です．\n", 2012-year);
      break;
    } else if ((1926<=year)&&(year<1986)){
    printf("あなたは昭和生まれで，%d 歳です．\n", 2012-year);
      break;
    } else if ((1986<=year)&&(year<=2012)){
    printf("あなたは平成生まれで，%d 歳です．\n", 2012-year);
      break;
    } else if ((year<1868)||(2012<year)){
    printf("もう一度入力してください\n");
    }
   }
return 0;
}