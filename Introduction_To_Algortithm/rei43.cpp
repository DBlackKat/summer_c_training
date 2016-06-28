#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	struct node *left;
	char name[12];
	struct node *right;
};
typedef struct node tnode;
tnode *talloc(void);

int main(){
	char dat[12];
	tnode *root,*p,*old;
	root = talloc();
	scanf(" %s",root->name);
	root->left = root->right = NULL;
	while(scanf("%s",dat) != EOF ){
		p = root;
		while(p!=NULL){
			old = p;
			if(strcmp(dat,p->name)<0)
				p = p->left;
			else
				p = p->right;
		}
		p = talloc();
		strcpy(p->name, dat);
		p ->left = p->right = NULL;
		if(strcmp(dat, old->name) <= 0)
			old->left = p;
		else
			old->right = p;
	}
	p = root;
	while(p->left != NULL){
		p = p->left;
	}
	printf("the smallest node: %s\n",p->name);
	p = root;
	while(p->right != NULL)
		p = p->right;
	printf("the smallest node: %s\n",p->name);

}

tnode *talloc(){
	return (tnode *)malloc(sizeof(tnode));
}

