#include <stdio.h>
#include <stdlib.h>

void swap(int *,int *);

int main(){
	static int a[100];
	int i,n,p,s;
	n = 0;
	while(scanf("%d",&heap[n])!=EOF)
		n++;
	
	for(i = n/2;i>=1;i--){
		p = i;	
		s = 2*p;
		while(s <= p ){
			if(s<n && heap[s+1]<heap[s])
				s++;
			if(heap[p] <= heap[s])
				break;
			swap(&heap[p],&heap[s]);
			p = s;
			s = 2*p;
		}
		for(i = 1;i<=n;i++)
			printf("%d ",heap[i]);	
	}
	return 0;
}

void swap(int *a,int *b){
	int c = *a;
	*a = *b;
	*b = c;
}