#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calc_fitness(int individual, int length, int **population);
void pairing(int num, int length, int **population, int **pair);

int main(void){
  int **population;
  int **pair;
  int *fitness;

  int num=10;
  int length=5;
  int i,j;

  population = malloc(sizeof(int *) * num);
  pair = malloc(sizeof(int *) * num);
  for(i=0;i<num;i++) {
    population[i] = malloc(sizeof(int) * length);
    pair[i] = malloc(sizeof(int) * length);
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

  pairing(num, length, population, pair);

  free(fitness);
  for(i=0;i<num;i++){
    free(pair[i]);
    free(population[i]);
  }
  free(pair);
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

void pairing(int num, int length, int **population, int **pair){
  int *shuffle;
  int r;
  int i,j;
  int tmp;

  shuffle = malloc(sizeof(double) * num);

  for(i=0;i<num;i++){
    shuffle[i] = i;
  }

  for(i=0;i<num;i++){
    r = rand()%num;
    tmp = shuffle[r];
    shuffle[r] = shuffle[i];
    shuffle[i] = tmp;
  }

  for(i=0;i<num;i++){
    for(j=0;j<length;j++){
      pair[i][j] = population[shuffle[i]][j];
    }
  }

  for(i=0;i<num;i++){
    for(j=0;j<length;j++){
      printf("%d",population[i][j]);
    }
    printf(">>>");
    for(j=0;j<length;j++){
      printf("%d",pair[i][j]);
    }
    printf("\n");
  }

  for(i=0;i<num;i++){
    for(j=0;j<length;j++){
      printf("%d",pair[i][j]);
    }
    printf("\n");
  }
}




