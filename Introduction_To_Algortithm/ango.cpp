#include <stdio.h>
#include <fcntl.h>
FILE fr,fw;

int main(void){
	int c,key = 0x07;
	fr = fopen("input.txt","r");
	fw = fopen("output.txt","w");

	
	while((c=getchar())!=EOF)
		putchar(c^key);

	return 0;
}