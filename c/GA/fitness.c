#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calc_fitness(int individual, int length, int **population);

int main(void){
  int **population;
  int *fitness;
  int num=10;
  int length=5;
  int i,j;

  population = malloc(sizeof(int *) * num);
  for(i=0;i<num;i++) {
    population[i] = malloc(sizeof(int) * length);
  }

  fitness = malloc(sizeof(double) * num);

  srand((unsigned)time(NULL));

  for(i=0;i<num;i++){
    for(j=0;j<length;j++){
      population[i][j] = rand()%2;
      printf("%d",population[i][j]);
    }

    fitness[i] = calc_fitness(i, length, population);
    printf("\tfittness = %d\n", fitness[i]);
  }

  free(fitness);
  for(i=0;i<num;i++){
    free(population[i]);
  }
  free(population);

  return 0;
}

int calc_fitness(int individual, int length, int **population){
  int i;
  int fitness = 0;
  for(i=0;i<length;i++){
    fitness = fitness + population[individual][i];
  }
  return 10*fitness;
}

