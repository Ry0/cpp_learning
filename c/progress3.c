#include <stdio.h>
#include <time.h>

void clocktime()
{
  clock_t t;
  t = clock() + CLOCKS_PER_SEC / 20;
  while (t > clock());
}

void PrintGaugeStart()// ループ終了した時に使う関数
{
  printf(" ");
  for (int j = 0; j < 20; j++) {
    printf("☆");
  }
  printf("   0 %%");
  fflush(stdout);
  printf("\r");
}

void PrintGauge(int iteration, int loop_count)// ■と□を20個プリントする関数
{
  int percent;

  printf(" ");
  for (int j = 1; j <= (float)iteration / loop_count * 20; j++) {
    printf("★");
  }
  for (int j = 1; j <= 20 - ((float)iteration / loop_count * 20); j++) {
    printf("☆");
  }
  percent = (float)iteration / loop_count * 100;
  printf("%5d %%", percent);
}


void PrintGaugeEnd()// ループ終了した時に使う関数
{
  printf(" ");
  for (int j = 0; j < 20; j++) {
    printf("★");
  }
  printf(" 100 %%\n");
  printf("\x1b[2B");
}


void PrintProgressBar(int iteration, int LoopNum)// 使うときのループ回数上限(LoopNum)と今のループ回数(iteration)
{
  int progress;
  int progress_count;

  progress_count = LoopNum / 20;
  progress = iteration % progress_count;
  if (progress == progress_count - 1) {
    PrintGauge(iteration, LoopNum);
  }
  fflush(stdout);
  printf("\r");
}


int main(void)
{
  int times = 650;

  PrintGaugeStart();
  for (int i = 0; i < times; i++) {
    clocktime();
    PrintProgressBar(i, times);// ループのなかの一番最後にこの関数書く
  }
  PrintGaugeEnd();// ループ終わりにこれを書く

  return 0;
}

