#include <stdio.h>
#include <algorithm>
using namespace std;

void normalSortingMethod(){
	const int NUM = 10;

	static int a[] = {56,25,88,100,61,55,67,67,76,56};
	int juni[NUM];

	for(int i=0;i<NUM;i++){
		juni[i] = 1;
		for(int j=0;j<NUM;j++)
			if(a[j]>a[i])
				juni[i]++;
	}

	for(int i=0;i<NUM;i++)
		printf("%6d %6d\n",a[i],juni[i]);
}
void betterSortingMethod(){
	const int NUM = 10;
	const int MAX = 100;
	const int MIN = 0;

	static int a[] = {56,25,88,100,61,55,67,67,76,56};
	int juni[MAX+2];
	fill(juni,juni+MAX+2,0);
	for(int i=0;i<NUM;i++)
		juni[a[i]]++;

	juni[MAX+1]  = 1;
	for(int i=MAX;i>=MIN;i--)
		juni[i] = juni[i] +juni[i+1];
	printf(" marks  rank  \n");
	for(int i=0;i<=NUM;i++){
		printf("%5d %5d\n",a[i],juni[a[i]+1]);
	}
}

void ifSmallerIsHigherRanking(){
	int MAX = 36;
	int MIN = -20;
	int NUM = 10;
	int Bias = 1-MIN;
	static int a[] = {-3,2,3,-1,-2,-6,2,-1,1,5};
	int i,juni[MAX+Bias+1];
	fill(juni,juni+MAX+Bias+1,0);

	for(int i=0;i<NUM;i++)
		juni[a[i]+Bias]++;
	
	juni[0] = 1;

	for(int i=MIN+Bias;i<=MAX+Bias;i++)
		juni[i] = juni[i] + juni[i-1];

	printf(" marks  rank  \n");
	for(int i=0;i<=NUM;i++){
		//result must add back bias and -1 as initialize in row 51
		printf("%5d %5d\n",a[i],juni[a[i]+Bias-1]);
	}
}
int main(){
	normalSortingMethod();
	betterSortingMethod();
	ifSmallerIsHigherRanking();
	return 0;
}