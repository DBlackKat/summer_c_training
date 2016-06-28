#include <stdio.h>
//this method is less computing intensive but only when a and b diff are small
int bcg1(int a,int b){
	while(a!=b){
		if(a > b)
			a = a-b;
		else
			b = b-a;
	}
	return a;
}
//this method is suitable when a and b are hugely diff
int bcg2(int a,int b){
	int k;
	while(b!=0){
		k = a%b;
		a = b;
		b = k;
	}
	return a;
}

int main(int argc,char *argv[]){
	int a,b;
	printf("Please input two numbers:  ");
	scanf("%d %d",&a,&b);
	printf("Their BCG : %d , %d",bcg1(a, b),bcg2(a, b));
}