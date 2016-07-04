#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode{
	struct tnode *left;
	char name[12];
	struct tnode *right;
};

struct tnode *talloc();
struct tnode *gentree(struct tnode *,char *);
void treewalk(struct tnode*);

int main(){
	char dat[12];
	struct tnode *root;
	root = NULL;
	while(scanf(" %s",dat)!= EOF){
		root = gentree(root, dat);
	}
	treewalk(root);
	return 0;
}

struct tnode *talloc(){
	return (struct tnode *)malloc(sizeof(struct tnode));
}

struct tnode *gentree(struct tnode *p, char *w){
	if(p==NULL){
		p = talloc();
		strcpy(p->name,w);
		p->left = p->right = NULL;
	}
	else if(strcmp(p->name,w)<0)
		p->right = gentree(p->right,w);
	else
		p->left = gentree(p->left,w);
	return p;
}

void treewalk(struct tnode *p){
	struct tnode *q,*w[128];
	int sp = 0;

	q = p;
	while(!(sp == 0 && q == NULL )){
		while(q!=NULL){
			w[sp++] = q;
			q = q->left;
		}
		sp--;
		printf("%s\n",w[sp]->name);
		q = w[sp]->right;
	}
}