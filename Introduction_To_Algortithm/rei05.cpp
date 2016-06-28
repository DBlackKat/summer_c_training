#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double rnd(){
	return (double)rand()/(INT32_MAX*1.0);
}
double findPI(){
	double x,y,pi;
	int i,in=0;
	for(i=0;i<10000;i++){
		x = rnd();
		y = rnd();
		if(x*x+y*y <=1)
			in++;
	}
	pi = in*4.0/10000;
	return pi;
}
double findAreaOval(){
	double x,y,s;
	int i,in=0;
	for(int i=0;i<10000;i++){
		x = rnd()*2;
		y = rnd();
		if(x*x/4 + y*y <= 1)
			in++;
	}
	return 4.0*(in*2.0)/10000;
}
int main(){
	printf("PI : %lf\n",findPI());
	printf("area of oval:  %lf\n",findAreaOval());

	return 0;
}