#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	static int heap[100];
	int n,i,s,p,w;
	n = 1;
	
	while(scanf(" %d",&heap[n])!= EOF){
		s = n;
		p = s/2;
		while( s >= 2 && heap[p] > heap[s]){ //if tree has smaller number then moving upward
			w = heap[p];
			heap[p] = heap[s];
			heap[s] = w;
			s = p;
			p = s/2;
		}
		n++;
	}
	for(i = 1;i<n;i++)
		printf("%d ",heap[i]);

	return 0;
}
