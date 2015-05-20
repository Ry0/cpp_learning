#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
  int human;
  int comp;
  int judge;
  int retry;

  srand(time(NULL));

  printf("------じゃんけんゲーム------\n");
  do{

    while(1){
      printf("じゃんけんポン・・・(0)ぐー (1)ちょき (2)ぱー\n");
      scanf("%d", &human);
      if(0<=human && human<=2){
	break;
      }else{
	printf("0~2の数字を入力してください。\n");
      }
    }

    printf("あなたは");
    switch(human){
    case 0: printf("”ぐー”"); break;
    case 1: printf("”ちょき”"); break;
    case 2: printf("”ぱー”"); break;
    }
    printf("ですね\n");

    comp = rand() % 3;
    printf("私は");
    switch(comp){
    case 0: printf("”ぐー”"); break;
    case 1: printf("”ちょき”"); break;
    case 2: printf("”ぱー”"); break;
    }
    printf("です\n");

    judge = (human - comp + 3) % 3;

   switch(judge){
    case 0: printf("引き分け\n"); break;
    case 1: printf("あなたの負けです\n"); break;
    case 2: printf("あなたの勝ちです\n"); break;
    }
   printf("もう一度やりますか・・・(0)いいえ (1)はい\n");
   scanf("%d", &retry);
  }while(retry==1);

  return 0;
}

