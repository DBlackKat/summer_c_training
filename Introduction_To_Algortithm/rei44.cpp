#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode{
	struct tnode *left;
	char name[12];
	struct tnode *right;
};

struct tnode *talloc(){
	return (struct tnode *)malloc(sizeof(struct tnode ));
}

struct tnode *gentree(struct tnode *p,char *w){
	if(p == NULL){
		p = talloc();
		strcpy(p->name,w);
		p->left = p->right = NULL;
	}
	else if(strcmp(w,p->name) < 0){
		p->left = gentree(p->left,w);
	}
	else
		p->right = gentree(p->right,w);
	return p;
}

int main(){
	char dat[12];
	struct tnode *root;
	root = NULL;
	
	while(scanf(" %s",dat)!= EOF){
		root = gentree(root,dat);
	}

	return 0;
}