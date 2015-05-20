#include <stdio.h>
#include <time.h>

int main(void){
  FILE *fp;
  time_t t;
  struct tm *local;

  time(&t);
  local = localtime(&t);

  if((fp = fopen("dt_dat", "w")) == NULL){
    printf("ファイルをオープンできません\n");
  }else{
    printf("現在の日付、時刻を書き出しました\n");
    fprintf(fp, "%d年, %d月, %d日, %d時, %d分, %d秒\n",
	    local->tm_year + 1900, local->tm_mon +1, local->tm_mday,
	    local->tm_hour, local->tm_min, local->tm_sec);
    fclose(fp);
  }
  return 0;
}
