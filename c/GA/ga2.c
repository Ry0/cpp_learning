#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int calc_fitness(int individual, int length, int **population);
double calc_fitness_bin(int individual, int length, int **population);
double average_fitness(int num, int *fitness);
double average_fitness_bin(int num, double *fitness_bin);
void pairing(int num, int length, int **population, int **pair);
void mutation(int mutation_rate, int length, int individual, int **population);
void crossover(int crossover_rate, int mutation_rate, int num, int length, int **population, int **pair);
void roulette(int num, int length, int **population, int *fitness);
void roulette2(int num, int length, int **population, double *fitness_bin);
double calc_bin2deci(int individual, int length, int **population);

int main(void){
  int **population;
  int **pair;
  int *fitness;
  double *fitness_bin;

  int generaton;
  int mutation_rate = 5;
  int num;
  int length;
  int crossover_rate = 50;
  int max_generation;
  int i,j;

  printf("個体数は？\n");
  scanf("%d", &num);
  printf("個体の長さは？\n");
  scanf("%d", &length);
  printf("最大の世代数は？\n");
  scanf("%d", &max_generation);

  population = malloc(sizeof(int *) * num);
  pair = malloc(sizeof(int *) * num);
  for(i=0;i<num;i++) {
    population[i] = malloc(sizeof(int) * length);
    pair[i] = malloc(sizeof(int) * length);
  }

  fitness = malloc(sizeof(double) * num);
  fitness_bin = malloc(sizeof(double) * num);

  srand((unsigned)time(NULL));

  //初期集団生成
  printf("初期集団\n");
  for(i=0;i<num;i++){
    for(j=0;j<length;j++){
      population[i][j] = rand()%2;
      printf("%d",population[i][j]);
    }
    fitness[i] = calc_fitness(i, length, population);
    fitness_bin[i] = calc_fitness_bin(i, length, population);
    printf(" = %lf", calc_bin2deci(i, length, population));
    printf("\tfittness = %lf\n", fitness_bin[i]);
  }

  for(generaton=1;generaton<=max_generation;generaton++){
    printf("\n%d世代目\n", generaton);

    pairing(num, length, population, pair);

    crossover(crossover_rate, mutation_rate, num, length, population, pair);

    for(i=0;i<num;i++){
      fitness[i] = calc_fitness(i, length, population);
      fitness_bin[i] = calc_fitness_bin(i, length, population);
      for(j=0;j<length;j++){
        printf("%d", population[i][j]);
      }
      printf(" = %lf", calc_bin2deci(i, length, population));
      printf("\tfitness = %lf\n", fitness_bin[i]);
    }

    if(average_fitness_bin(num,fitness_bin)>1.84){
      printf("平均適合度は%.3lfとなり%d世代目に目標適合度に到達\n", average_fitness_bin(num,fitness_bin), generaton);
      break;
    }

    roulette2(num,length,population,fitness_bin);
  }


  //for(i=0;i<num;i++){
    //roulette(num, length, population, fitness);
    //mutation(mutation_rate, length, i, population);
  //}
  //crossover(crossover_rate, num, length, population, pair);

  printf("\n終了後\n");
  for(i=0;i<num;i++){
    for(j=0;j<length;j++){
      printf("%d",population[i][j]);
    }
    fitness_bin[i] = calc_fitness_bin(i, length, population);
    printf(" = %lf", calc_bin2deci(i, length, population));
    printf("\tfittness = %lf\n", fitness_bin[i]);
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
  return fitness;
}

double calc_fitness_bin(int individual, int length, int **population){
  int i;
  double fitness = 0;
  double tmp = 0;
  double x;

  for(i=0;i<length;i++){
    tmp = tmp + pow(2,i)*population[individual][i];
  }
  x = tmp/(pow(2,length) - 1);
  fitness = sin(3*x) + 0.5*sin(9*x) + sin(15*x + 50);
  return fitness;
}

double calc_bin2deci(int individual, int length, int **population){
  int i;
  double deci = 0;
  double tmp = 0;
  double x;

  for(i=0;i<length;i++){
    tmp = tmp + pow(2,i)*population[individual][i];
  }
  deci = tmp/(pow(2,length) - 1);
  return deci;
}

double average_fitness_bin(int num, double *fitness_bin){
  int i;
  double sum=0;

  for(i=0;i<num;i++){
    sum += fitness_bin[i];
  }
  return (double)sum/(double)num;
}

double average_fitness(int num, int *fitness){
  int i;
  int sum=0;

  for(i=0;i<num;i++){
    sum += fitness[i];
  }
  return (double)sum/(double)num;
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

  // for(i=0;i<num;i++){
  //   for(j=0;j<length;j++){
  //     printf("%d",population[i][j]);
  //   }
  //   printf(">>>");
  //   for(j=0;j<length;j++){
  //     printf("%d",pair[i][j]);
  //   }
  //   printf("\n");
  // }

  // for(i=0;i<num;i++){
  //   for(j=0;j<length;j++){
  //     printf("%d",pair[i][j]);
  //   }
  //   printf("\n");
  // }
}

void mutation(int mutation_rate, int length, int individual, int **population){
  int i;

  for(i=0;i<length;i++){
    if(mutation_rate>rand()%100){
      population[individual][i] =! population[individual][i];
    }
  }
}

void crossover(int crossover_rate, int mutation_rate, int num, int length, int **population, int **pair){
  int i,j;
  int cross_point;

  // for(i=0;i<num;i++){
  //   for(j=0;j<length;j++){
  //     pair[i][j] = population[i][j];
  //   }
  // }

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
      mutation(mutation_rate, length, i, population);
      mutation(mutation_rate, length, i+1, population);
    }else{
      for(j=0;j<length;j++){
        population[i][j] = pair[i][j];
        population[i+1][j] = pair[i+1][j];
      }
    }
  }
}

void roulette(int num, int length, int **population, int *fitness){
  int i,j,k;
  int sum_fitness;
  int **new_population;
  double *roulette;
  double *ac_roulette;
  double r;

  new_population = malloc(sizeof(int *) * num);
  for(i=0;i<num;i++) {
    new_population[i] = malloc(sizeof(int) * length);
  }

  roulette = malloc(sizeof(double) * num);
  ac_roulette = malloc(sizeof(double) * num);

  sum_fitness = 0;
  for(i=0;i<num;i++){
    sum_fitness = sum_fitness + fitness[i];
  }

  roulette[0] = (double)fitness[0]/(double)sum_fitness;
  ac_roulette[0] = roulette[0];
  //printf("roulette[%d]=%lf ac_roulette[%d]=%lf\n", 0, roulette[0], 0, ac_roulette[0]);

  for(i=1;i<num;i++){
    roulette[i] = (double)fitness[i]/(double)sum_fitness;
    ac_roulette[i] = roulette[i] + ac_roulette[i-1];
    //printf("roulette[%d]=%lf ac_roulette[%d]=%lf\n", i, roulette[i], i, ac_roulette[i]);
  }

  for(i=0;i<num;i++){
    r = (double)rand()/(double)RAND_MAX;
    for(j=0;j<num;j++){
      if(r<=ac_roulette[j]){
        //printf("r=%lf ac_roulette[%d]=%lf\n", r, j, ac_roulette[j]);
        for(k=0;k<length;k++){
          new_population[i][k] = population[j][k];
        }
        break;
      }
    }
  }

  for(i=0;i<num;i++){
    for(j=0;j<length;j++){
      population[i][j] = new_population[i][j];
    }
  }

  free(ac_roulette);
  free(roulette);
  for(i=0;i<num;i++){
    free(new_population[i]);
  }
  free(new_population);

}

void roulette2(int num, int length, int **population, double *fitness_bin){
  int i,j,k;
  double sum_fitness;
  int **new_population;
  double *roulette;
  double *ac_roulette;
  double r;

  new_population = malloc(sizeof(int *) * num);
  for(i=0;i<num;i++) {
    new_population[i] = malloc(sizeof(int) * length);
  }

  roulette = malloc(sizeof(double) * num);
  ac_roulette = malloc(sizeof(double) * num);

  sum_fitness = 0;
  for(i=0;i<num;i++){
    sum_fitness = sum_fitness + fitness_bin[i];
  }

  roulette[0] = (double)fitness_bin[0]/(double)sum_fitness;
  ac_roulette[0] = roulette[0];
  //printf("roulette[%d]=%lf ac_roulette[%d]=%lf\n", 0, roulette[0], 0, ac_roulette[0]);

  for(i=1;i<num;i++){
    roulette[i] = (double)fitness_bin[i]/(double)sum_fitness;
    ac_roulette[i] = roulette[i] + ac_roulette[i-1];
    //printf("roulette[%d]=%lf ac_roulette[%d]=%lf\n", i, roulette[i], i, ac_roulette[i]);
  }

  for(i=0;i<num;i++){
    r = (double)rand()/(double)RAND_MAX;
    for(j=0;j<num;j++){
      if(r<=ac_roulette[j]){
        //printf("r=%lf ac_roulette[%d]=%lf\n", r, j, ac_roulette[j]);
        for(k=0;k<length;k++){
          new_population[i][k] = population[j][k];
        }
        break;
      }
    }
  }

  for(i=0;i<num;i++){
    for(j=0;j<length;j++){
      population[i][j] = new_population[i][j];
    }
  }

  free(ac_roulette);
  free(roulette);
  for(i=0;i<num;i++){
    free(new_population[i]);
  }
  free(new_population);

}
