#include <math.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

float f1(float x, int intensity);
float f2(float x, int intensity);
float f3(float x, int intensity);
float f4(float x, int intensity);



#ifdef __cplusplus
}
#endif



float x,p=0,sub,t;
clock_t start,end;
double curr_time;
int function_id;
int a;
int b;
int n;
int intensity;
int main (int argc, char* argv[]) {



  if (argc < 6) {
    fprintf(stderr, "usage: %s <functionid> <a> <b> <n> <intensity>", argv[0]);
    return -1;
  }
  start=clock(); // start clock
  int i;

  sscanf(argv[1],"%d", &function_id);
  sscanf(argv[2],"%d", &a);
  sscanf(argv[3],"%d", &b);
  sscanf(argv[4],"%d", &n);
  sscanf(argv[5],"%d", &intensity);

  sub=b-a;
  t=sub/n;
  for(i=0;i<=n-1;i++){
    x=a+((i+0.5)*t);

    switch (function_id) {
      case 1: p = p+f1(x,intensity);
        break;
      case 2: p = p+f2(x,intensity);
        break;
      case 3: p = p+f3(x,intensity);
        break;
      case 4: p = p+f4(x,intensity);
        break;
      default:printf("wrong id");
        break;
    }
  }
  p=p*t;
  end=clock();// end clock

  fprintf(stdout, "%f\n", p);
  curr_time =((double)end-start)/CLOCKS_PER_SEC;
  //fprint() allows you to tell which output you want to print to.
  fprintf(stderr, "%f\n", curr_time);
  return 0;
}
