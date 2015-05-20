#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  int i,ok,ng,r;

  srand(1225);  // 「乱数の種」を固定値で指定

  ok=0; ng=0;

  for(i=0;i<100000;i++)
    {
      r=rand() % 6 + 1;
      if(r==3)
	{
	  ok++;
	}
      else
	{
	  ng++;
	}
    }
  printf("OK:%d 回 NG:%d 回  OKの率:%12.8f %%\n",
	 ok,ng,(100.0*ok)/(ok+ng));
  return 0;
}