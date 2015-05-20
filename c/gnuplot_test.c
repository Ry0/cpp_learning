#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

int main(int argc, char **argv)
{
FILE *gid;
int i;
int key;
double x;
gid=popen("gnuplot -persist","w");
for (i=0; i<1000 ;i++){
x = 0.03*i;
fprintf(gid,"plot sin(x-%f*pi)\n",x);
usleep(20000);
}
pclose(gid);
return 0;
}
