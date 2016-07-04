#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){
	int w = *a;*a = *b;*b = w;
}

int main(){
	static int heap[100];
	int n,i,s,p,m;

	n = 1;
	while(scanf("%d ",(heap+n))!=EOF){
		s = n;
		p = s/2;
		while(s>=2 && heap[p]> heap[s]){
			swap(&heap[p],&heap[s])
			s = p;
			p = s/2;
		}
		n++;
	}
	n--;
	m = n;
	while(n>1){
		swap(&heap[1],&heap[n]);
		n--;
		p = 1;s=2*p;
		while(s<=n){
			if(s < n && heap[s+1] < heap[s] )
				s++;
			if(heap[p] <= heap[s])
				break;
			swap(&heap[p],&heap[s]);
			p = s; s = 2*p;
		}
	}
	for(i = 1;i<=m;i++)
		printf("%d ",heap[i]);

	return 0;
}