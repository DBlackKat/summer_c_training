#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctime>
using namespace std;
bool isPrime1(int n){
	int i,Limit;
	if(n>=2){
		Limit = (int)sqrt(n);
		for(i = Limit;i>1;i--){
			if(n%i == 0)
				break;
		}
		if(i==1)
			return true;
		else
			return false;
	}
	return false;
}
//big o notation is : n*sqrt(n)/2
void findPrime(int M){
	int *prime;
	prime = new int [M/2+1];
	int i,n,m=0,Limit;
	for(n=2;n<=M;n++){
		Limit = (int)sqrt(n);
		for(i=Limit;i>1;i--){
			if(n%i == 0)
				break;
		}
		if(i==1)
			prime[m++] = n;
	}
	printf("\nAll prime Number\n");
	for(i=0;i<m;i++)
		printf("%5d",prime[i]);
	delete prime;
}
void findPrime2(int M){	
	int i,j,Limit;
	int *prime;
	prime = new int [M];
	for(i=2;i<=M;i++)
		prime[i] = 1;
	Limit = (int)sqrt(M);
	for(int i=2;i<=Limit;i++)
		if(prime[i] == 1)
			for(j=2*i;j<=M;j++)
				if(j%i==0)
					prime[j] = 0;
	printf("\nAll prime Number\n");
	for(i=0;i<M;i++)
		if(prime[i] == 1)
			printf("%5d",i);
	delete prime;
}
void derive(int n){
	int a=2;
	while(n>=a*a){
		if(n%a == 0){
			printf("%d*",a);
			n = n/a;
		} 
		else
			a++;
	}
	printf("%d\n",n);
	return;
}
int main(){
	int n;
	double elapsed_secs;
	clock_t begin = clock();

	findPrime(1000);

	clock_t end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	printf("\nTime taken %lf\n",elapsed_secs);
	
	//second finder
	clock_t begin2 = clock();
	
	findPrime2(1000);

	clock_t end2 = clock();
	elapsed_secs = double(end2 - begin2) / CLOCKS_PER_SEC;
	printf("\nTime taken %lf\n",elapsed_secs);
	while(printf("Input a number: "),scanf(" %d",&n) !=EOF){
		if(isPrime1(n))
			printf("%d is a prime number\n",n);
		else
			printf("%d is not a prime number\n",n);
		derive(n);
	}

	return 0;	
}

