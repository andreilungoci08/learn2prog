#include <stdio.h>
#include <stdlib.h>

struct _retire_info{
  int months;
  double contributions;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

int age_year(int x){
  return x/12;
}

int age_month(int x){
  return x-age_year(x)*12;
}

void retirement(int startAge, double initial, retire_info working, retire_info retired){
  double b;
  int i=0;

  b=initial;

  printf("Age %3d month %2d you have $%.2lf\n",age_year(startAge),age_month(startAge),b);
  while(i<working.months){
    b=b+b*working.rate_of_return+working.contributions;
    startAge++;
    printf("Age %3d month %2d you have $%.2lf\n",age_year(startAge),age_month(startAge),b);
    i++;
  }

  i=0;

  while(i<retired.months-1){
    b=b+b*retired.rate_of_return+retired.contributions;
    startAge++;
    printf("Age %3d month %2d you have $%.2lf\n",age_year(startAge),age_month(startAge),b);
    i++;
  }
}

int main(){
  int startAge=327;
  double initial=21345;
  retire_info working, retired;

  working.months=489;
  working.rate_of_return=0.045/12;
  working.contributions=1000;
  retired.months=384;
  retired.rate_of_return=0.01/12;
  retired.contributions=-4000;

  retirement(startAge, initial, working, retired);

  return EXIT_SUCCESS;

}
