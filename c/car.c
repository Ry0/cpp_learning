#include <math.h>
#include <stdio.h>

typedef struct {
  int x;
  int y;
} point;

typedef struct {
  double fuel;
  point pt;
} car;

void put_info(car c){
  printf("現在位置：(%d,%d)\n", c.pt.x, c.pt.y);
  printf("残り燃料：%.2fリットル\n", c.fuel);
}

int move(car *c, int dx, int dy){
  double dist;
  dist = sqrt(pow(dx, 2)+pow(dy, 2));
  if(dist > c->fuel){
    return 0;
  }
  c->pt.x += dx;
  c->pt.y += dy;
  c->fuel -= dist;
  return 1;
}

int main(void){
  car mycar = {90.0, {0, 0}};
  while(1){
    int slct;
    int dx ,dy;
    put_info(mycar);
    printf("移動しますか[Yes=>1/No=>0]:");
    scanf("%d", &slct);
    if(slct == 0){
      break;
    }
    printf("X方向の移動距離：");
    scanf("%d", &dx);
    printf("Y方向の移動距離：");
    scanf("%d", &dy);

    if(!move(&mycar, dx, dy)){
      printf("燃料不足です\n");
    }
  }
  return 0;
}
