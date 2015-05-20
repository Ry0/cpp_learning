#include "./../../../header/cv_obstacle_avoidance.h"
#include "sys/time.h"

int split_character(char *work){
  static char GPRMC[12];
  static char GPS_time[12];
  static char HN[12];
  static char status[12];
  static char E[12];
  static char UTC[12];
  char *tok = NULL;
  static int i;
  char *headp = NULL;
  char *tailp = NULL;
  for(i=0;i<256;i++){
    GPRMC[i] = '\0';
    GPS_time[i] = '\0';
    HN[i] = '\0';
    status[i] = '\0';
    E[i] = '\0';
    UTC[i] = '\0';
  }
  headp = (char *)malloc(256);
  tailp = (char *)malloc(256);

  headp = work;
  tailp = work;
  //  printf("RAW\t:\t%s",work); //RAWの文字列に改行コードが含まれているため改行コードをなしに
  tailp  = strchr(tailp,',');
  *tailp = '\0';
  strcpy(&GPRMC[0],headp);

  tailp++;
  headp  = tailp;
  tailp  = strchr(headp,',');
  *tailp = '\0';
  strcpy(&GPS_time[0],headp);

  tailp++;
  headp  = tailp;
  tailp  = strchr(headp,',');
  *tailp = '\0';
  strcpy(&status[0],headp);

  tailp++;
  headp  = tailp;
  tailp  = strchr(headp,',');
  *tailp = '\0';
  strcpy(&La[0],headp);

  tailp++;
  headp  = tailp;
  tailp  = strchr(headp,',');
  *tailp = '\0';
  strcpy(&HN[0],headp);

  tailp++;
  headp  = tailp;
  tailp  = strchr(headp,',');
  *tailp = '\0';
  strcpy(&Lo[0],headp);

  tailp++;
  headp  = tailp;
  tailp  = strchr(headp,',');
  *tailp = '\0';
  strcpy(&E[0],headp);

  tailp++;
  headp  = tailp;
  tailp  = strchr(headp,',');
  *tailp = '\0';
  strcpy(&Vel[0],headp);

  tailp++;
  headp  = tailp;
  tailp  = strchr(headp,',');
  *tailp = '\0';
  strcpy(&Deg[0],headp);

  tailp++;
  headp  = tailp;
  tailp  = strchr(headp,',');
  *tailp = '\0';
  strcpy(&UTC[0],headp);

  tailp++;
  headp  = tailp;
  tailp  = strchr(headp,',');
  *tailp = '\0';
  strcpy(&henkaku[0],headp);

  tailp++;
  headp  = tailp;
  tailp  = strchr(headp,',');
  *tailp = '\0';
  strcpy(&henni[0],headp);
  /* free(headp); */
  /* free(tailp); */
  return 0;
}

/* int moving_average(int loop, double* GPSdata){ */
/*   static int a, b; */
/*   static double sum = 0; */
/*   static double ave = 0; */

/*   for(a=0, a<loop, a++){ */
/*     moving_average_data[a%10] = GPSdata; */
/*     for(b=0, b<10, b++){ */
/*       sum = sum + moving_average_data[b]; */
/*     } */
/*     ave = sum/10; */
/*   } */
/*   return ave; */

int main(void){
  static char gps_buff[255];
  static int  i=0,j=0,k=0,l=0,m=0;
  static char GPGA[128];
  static char GPS_time[128];
  static char work[256];
  static char N[128];
  static double moving_average_data1[10];
  static double moving_average_data2[10];
  static double moving_average_data = 0;
  static double angle_deg1=0, angle_deg2=0;
  static double angle_dir1=0, angle_dir2=0;
  static double distance_deg=0, abs_distance_deg=0
  static double distance_dir=0, abs_distance_dir=0
  static double cashe_deg[10];
  static double cashe_dir[10];
  static int res = 0;
  static double x,y = 0;
  //la is latitude (ido).  lo is longitude (keido).
  //HDOP is check the trustworthiness of data. N is the number of satellite.
  static int sp;
  static int gps_loop = 0;
  static double dir_last;
  GPSdata.la=0;
  GPSdata.lo=0;
  GPSdata.sate=1;
  static double len;
  static double len_last;
  static STATE metoru[2];
  static double sum1=0,sum2=0;
  static double ave_deg=0, ave_dir=0;
  struct timeval s, e;
  FILE *fp;
  sleep(1);
  //open
  fd1 = open(GPS_DEVICE, O_RDWR | O_NOCTTY | O_NONBLOCK);
  fcntl(fd1,F_SETFL,0);
  if(fd1 < 0){
    perror(GPS_DEVICE);
    exit(-1);
  }
  /*-----------------*/
  /* シリアル通信初期化 */
  /*-----------------*/
  tcgetattr(fd1,&oldtio); //現在の設定を保存しておく
  bzero(&newtio, sizeof(newtio)); //新しい設定のためのプロファイルを用意
  //ボードレートなどを設定
  newtio.c_cflag = GPS_BAUDRATE|CRTSCTS|CS8|CLOCAL|CREAD;
  newtio.c_iflag = IGNPAR | ICRNL;
  newtio.c_oflag = 0;
  newtio.c_lflag = ICANON; //カノニカル入力
  //newtio.c_lflag = 0; //非カノニカル入力
  /* newtio.c_cc[VINTR]	= 0; */
  /* newtio.c_cc[VQUIT]	= 0; */
  /* newtio.c_cc[VERASE]	= 0; */
  /* newtio.c_cc[VKILL]	= 0; */
  /* newtio.c_cc[VEOF]	= 0; */
  newtio.c_cc[VTIME]	= 0; //キャラクタ間タイマは未使用
  //newtio.c_cc[VMIN]	= 100; //ここで指定した文字数受けとるまでブロックする
  /* newtio.c_cc[VSWTC]	= 0; */
  /* newtio.c_cc[VSTART]	= 0; */
  /* newtio.c_cc[VSTOP]	= 0; */
  /* newtio.c_cc[VSUSP]	= 0; */
  /* newtio.c_cc[VEOL]	= 0; */
  /* newtio.c_cc[VREPRINT] = 0; */
  /* newtio.c_cc[VDISCARD] = 0; */
  /* newtio.c_cc[VWERASE]  = 0; */
  /* newtio.c_cc[VLNEXT]	= 0; */
  /* newtio.c_cc[VEOL2]	= 0; */

  //現在の設定をクリア
  tcflush(fd1,TCIFLUSH);
  //新しい設定を反映
  tcsetattr(fd1,TCSANOW,&newtio);

  printf("(GPS)ループ開始\n");
  if((fp = fopen("getlogGPS5.dat","w"))== NULL){
    printf("\aファイルをオープンできません。\n");
  }
  gettimeofday(&s, NULL);
  while(1){
    res = read(fd1, gps_buff, 255);
    //printf("res = %p,gps_buff = %s",res,gps_buff);//gps_buffの文字列に改行コードが含まれているためprintfの改行コードなし
    if(res == 0x1)
      continue;
    gps_buff[res] = '\0';
    strcpy(work, gps_buff);
    split_character(work);
    //gps_buffのクリア
    for(i=0;i<255;i++){
      gps_buff[i] = '\0';
    }
    //文字データを数字に変換
    GPSdata.la = vlum_convertK(La);
    GPSdata.lo = vlum_convertK(Lo);
    gps_state.deg = 450 - atof(Deg);//angle of robot going by GPS
    gps_state.gvel = 0.514444*atof(Vel);//[knot] to [m/s]
    //printf("[GPS] La == %f, Lo == %f\n",GPSdata.la ,GPSdata.lo);
    if(gps_state.deg > 360){
      gps_state.deg = gps_state.deg - 360;
    }
    //GPS2m is from ./GXconverter.c
    //gps_state.pos = GPS2m(GPSdata.la, GPSdata.lo, &WORLD_0);
    gps_state.pos.x = GPSdata.la;
    gps_state.pos.y = GPSdata.lo;
    /* for(i=0;i<store_gps-1;i++){ */
    /*   store_gpsdata[i]=store_gpsdata[i+1]; */
    /* } */
    /* store_gpsdata[store_gps-1].pos.x = GPSdata.la; */
    /* store_gpsdata[store_gps-1].pos.y = GPSdata.lo; */
    //printf("store_gpsdata[0].pos.x = %f\n, store_gpsdata[0].pos.y = %f\n",store_gpsdata[0].pos.x,store_gpsdata[0].pos.y);
    //printf("store_gpsdata[99].pos.x = %f\n, store_gpsdata[99].pos.y = %f\n",store_gpsdata[store_gps-1].pos.x,store_gpsdata[store_gps-1].pos.y);
    //gps_state.pos = GPS2m(GPSdata.la, GPSdata.lo, &WORLD_0);
    //metoru[0].pos=GPS2m(store_gpsdata[store_gps-1].pos.x,store_gpsdata[store_gps-1].pos.y,&WORLD_0); //now position
    /* metoru[1].pos=GPS2m(store_gpsdata[0].pos.x,store_gpsdata[0].pos.y,&WORLD_0); //old position */
    /* x=metoru[0].pos.x - metoru[1].pos.x; */
    /* y=metoru[0].pos.y - metoru[1].pos.y; */
    gps_state.mpos=GPS2m(GPSdata.la, GPSdata.lo, &WORLD_0);
    x=gps_state.mpos.x-gps_state_last.mpos.x;
    y=gps_state.mpos.y-gps_state_last.mpos.y;
    gps_state.dir = atan2(y,x);
    /* if(gps_state.deg < 270){ */
    /*   gps_state.deg = gps_state.deg+90; */
    /* }else{ */
    /*   gps_state.deg = gps_state.deg + 90; */
    /*   gps_state.deg = gps_state.deg/360; */
    /* } */
    if(gps_state.dir < 0){
      gps_state.dir = PI + (PI - fabs(gps_state.dir));
    }
    if(fabs(gps_state.dir)<0.001){
      gps_state.dir = gps_state_last.dir;
    }
    for(i=0;i<10;i++){
      usleep(100);
    }
    gps_state_last = gps_state;

    printf("%dループ\n",gps_loop);

    moving_average_data1[gps_loop%10] = gps_state.deg;
    for(l=0; l<9; l++){
      angle_deg1 = moving_average_data1[l];
      angle_deg2 = moving_average_data1[l+1];
      distance_deg = angle_deg2 - angle_deg1;
      abs_distance_deg = fabs(distance_deg);
      if(abs_distance_deg<180){
        abs_distance_deg = abs_distance_deg;
      }else{
        if(distance_deg < 0){
          distance_deg = distance_deg + 360;
        }else{
          distance_deg = distance_deg - 360;
        }
      }
      cashe_deg[l+1] = distance_deg;
    }
    for(l=1; l<10; l++){
      moving_average_data1[l] = moving_average_data1[l-l] + cashe_deg[l];
    }
    for(l=0; l<10; l++){
      sum1 = sum1 + moving_average_data1[l];
    }
    ave_deg = sum1/10;
    sum1 = 0;
    printf("GPSからのデータの移動平均 %lf\n",ave_deg);


    moving_average_data2[gps_loop%10] = gps_state.dir*180/PI;
    for(m=0; m<9; m++){
      angle_dir1 = moving_average_data2[m];
      angle_dir2 = moving_average_data2[m+1];
      distance_dir = angle_dir2 - angle_dir1;
      abs_distance_dir = fabs(distance_dir);
      if(abs_distance_dir<180){
        abs_distance_dir = abs_distance_dir;
      }else{
        if(distance_dir < 0){
          distance_dir = distance_dir + 360;
        }else{
          distance_dir = distance_dir - 360;
        }
      }
      cashe_dir[m+1] = distance_dir;
    }
    for(m=1; m<10; m++){
      moving_average_data2[m] = moving_average_data2[m-l] + cashe_deg[m];
    }
    for(m=0; m<10; m++){
      sum2 = sum2 + moving_average_data2[m];
    }
    ave_dir = sum2/10;
    sum2 = 0;
    printf("計算によるデータの移動平均 %lf\n",ave_dir);


    moving_average_data = (ave_deg + ave_dir)/2;
    printf("2つの平均 %lf\n",moving_average_data);

    fprintf(fp,"%d\t%f\t%f\t%f\t%f\t%f\n", gps_loop, GPSdata.la, GPSdata.lo, gps_state.deg, gps_state.dir*180/PI, moving_average_data);
    res = read(fd1, gps_buff, 255); //ChangeLog(2013.05.16)
    gps_loop += 1;

    if(gps_loop>=1000){
      break;
    }
  }
  gettimeofday(&e,NULL);
  printf("time = %lf\n",(e.tv_sec - s.tv_sec)+(e.tv_usec - s.tv_usec)*1.0E-6);
  printf("周期 = %lf\n",((e.tv_sec - s.tv_sec)+(e.tv_usec - s.tv_usec)*1.0E-6)/300);
  //fclose(fp);
  return 0;
}



















