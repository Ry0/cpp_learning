#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calc_fitness(int individual, int length, int **population);
void pairing(int num, int length, int **population, int **pair);
void mutation(int mutation_rate, int length, int individual, int **population);
void crossover(int crossover_rate, int num, int length, int **population, int **pair);


int main(void){
  int **population;
  int **pair;
  int *fitness;

  int mutation_rate = 50;
  int num=10;
  int length=5;
  int crossover_rate = 50;
  int i,j;

  population = malloc(sizeof(int *) * num);
  pair = malloc(sizeof(int *) * num);
  for(i=0;i<num;i++) {
    population[i] = malloc(sizeof(int) * length);
    pair[i] = malloc(sizeof(int) * length);
  }

  fitness = malloc(sizeof(double) * num);

  srand((unsigned)time(NULL));

  printf("initial\n");
  for(i=0;i<num;i++){
    for(j=0;j<length;j++){
      population[i][j] = rand()%2;
      printf("%d",population[i][j]);
    }
    fitness[i] = calc_fitness(i, length, population);
    printf("\tfittness = %d\n", fitness[i]);
  }

  // for(i=0;i<num;i++){
  //   mutation(mutation_rate, length, i, population);
  // }
  crossover(crossover_rate, num, length, population, pair);

  printf("mutation\n");
  for(i=0;i<num;i++){
    for(j=0;j<length;j++){
      printf("%d",population[i][j]);
    }
    fitness[i] = calc_fitness(i, length, population);
    printf("\tfittness = %d\n", fitness[i]);
  }
  //pairing(num, length, population, pair);

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

void mutation(int mutation_rate, int length, int individual, int **population){
  int i;

  for(i=0;i<length;i++){
    if(mutation_rate>rand()%100){
      population[individual][i] =! population[individual][i];
    }
  }
}

void crossover(int crossover_rate, int num, int length, int **population, int **pair){
  int i,j;
  int cross_point;

  for(i=0;i<num;i++){
    for(j=0;j<length;j++){
      pair[i][j] = population[i][j];
    }
  }

  for(i=0;i<(num-1);i=i+2){
    if(rand()%100<crossover_rate){
      cross_point = rand()%(length-1)+1;
      printf("交叉位置は%d番目\n", cross_point);
      for(j=0;j<cross_point;j++){
        population[i][j] = pair[i+1][j];
        population[i+1][j] = pair[i][j];
      }
      for(j=cross_point;j<length;j++){
        population[i][j] = pair[i][j];
        population[i+1][j] = pair[i+1][j];
      }
    }else{
      for(j=0;j<length;j++){
        population[i][j] = pair[i][j];
        population[i+1][j] = pair[i+1][j];
      }
    }
  }
}


