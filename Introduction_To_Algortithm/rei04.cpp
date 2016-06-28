#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int irnd(int n){
	return (int)(rand()/(INT32_MAX*1.0)*n+1);
}

void notEfficientWay(){
	const int N = 20;
	int i,j,flag,a[N+1];
	a[1] = irnd(N);
	for(i=2;i<=N;i++){
		do{
			a[i] = irnd(N);
			flag = 0;
			for(j=1;j<i;j++)
				if(a[i] == a[j]){
					flag = 1;
					break;
				}
		}while(flag);
	}
	for(i=1;i<=N;i++)
		printf("%d ",a[i]);
}
void efficientWay(){
	const int N = 20;
	int i,j,d,a[N];
	for(i=0;i<N;i++)
		a[i] = i+1;
	for(i=N;i>1;i--){
		j = irnd(i-1);
		d = a[i-1];
		a[i-1] = a[j-1];
		a[j-1] = d;
	}
	for(i=0;i<N;i++)
		printf("%d ",a[i]);

}
int main(){
	printf("8: %d, 16: %d, 32: %d\n",INT8_MAX,INT16_MAX,INT32_MAX);
	notEfficientWay();
	printf("\n");
	efficientWay();
	return 0;
}