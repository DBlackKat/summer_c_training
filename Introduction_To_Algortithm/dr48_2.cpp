#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){
	int w = *a;*a = *b;*b = w;
}
void shiftDown(int,int,int *);

int main(){
	static int heap[100];
	int i,n,m;
	n = 1;
	while(scanf(" %d",&heap[n])!= EOF){
		n++;
	}
	n--;
	for(i = n/2;i>=1;i--)
		shiftDown(i, n, heap);
	m = n;
	while(n>1){
		swap(&heap[1],&heap[n]);
		n--;
		shiftDown(1, n, heap);
	}
	for(i = 1;i<=m;i++)
		printf("%d ",heap[i]);
}

void shiftDown(int p,int n,int heap[]){
	int s;
	s = 2*p;
	while(s<=n){
		if(s<n && heap[s+1] > heap[s])
			s++;
		if(heap[p] >= heap[s])
			break;
		swap(&heap[p],&heap[s]);
		p =s;s=2*p;
	}
}