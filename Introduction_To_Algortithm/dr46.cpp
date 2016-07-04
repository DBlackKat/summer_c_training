#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	while(scanf(" %s",dat) != EOF){
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

void treewalk(struct tnode *p){
	struct connect {
		struct tnode *node;
		char *parent;
		char direct;
	}q[128],w[128];
	int i,child,n,level;

	child = 1;level=0;
	q[0].node = p;
	q[0].parent = new char [strlen("root")];
	strcmp(q[0].parent,"root");
	q[0].direct = ' ';
	do{
		n = 0;
		printf("level %d :\n",level);
		for(i = 0;i<child;i++){
			printf("%12s->%c:%12s\n",q[i].parent,q[i].direct,q[i].node->name);
			if(q[i].node->left != NULL){
				w[n].parent = q[i].node->name;
				w[n].direct = 'l';
				w[n].node = q[i].node->left;
				n++;
			}
			if(q[i].node->right != NULL){
				w[n].parent = q[i].node->name;
				w[n].direct = 'r';
				w[n].node = q[i].node->right;
				n++;
			}
		}
		child = n;
		for(i = 0;i<child;i++)
			q[i] = w[i];
		level++;
	}while(child!=0);
}