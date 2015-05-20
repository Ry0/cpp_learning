#include <stdio.h>
#include <math.h>

int main(void)
{
  int i,j;
  for(i=1;i<100;i++)
    {
      for(j=1;j<100;j++)
	{
	  printf(" %2d",i*j);
	}
      printf("\n");
    }
  return 0;
}
