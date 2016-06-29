#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode{
	struct tnode *left;
	char name[12];
	struct tnode *right;
};
struct tnode *talloc(void );
struct tnode *gentree(struct tnode *,char * );
void treewalk(struct tnode *);

int main(){
	char dat[12];
	struct tnode *root;
	root = NULL;
	while(scanf("%s",dat) == NULL){
		root = gentree(root,dat);
	}
	treewalk(root);

	return 0;
}

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

void treewalk(struct tnode *p,char *w){
	if(p==NULL){
		treewalk(p->left);
		printf("%s\n",p->name);
		treewalk(p->right);
	}
}