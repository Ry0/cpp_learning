#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
  int **population;
  int num=10;
  int length=5;
  int i,j;

  population = malloc(sizeof(int *) * num);
  for(i=0;i<num;i++) {
    population[i] = malloc(sizeof(int) * length);
  }

  srand((unsigned)time(NULL));

  for(i=0;i<num;i++){
    for(j=0;j<length;j++){
      population[i][j] = rand()%2;
      printf("%d",population[i][j]);
    }
    printf("\n");
  }

  for(i=0;i<num;i++){
    free(population[i]);
  }
  free(population);
  return 0;
}
