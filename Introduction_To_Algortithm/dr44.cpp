#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode{
	struct tnode *left;
	char name[12];
	struct tnode *right;
};
struct tnode *talloc();
struct tnode *gentree();
struct tnode *search();

int main(){
	char key[12];
	struct tnode *root,*p;
	root = NULL;
	while(scanf("%s",key) != EOF){
		root = gentree(root,key);		
	}
	rewind(stdin);
	while(printf("Search name -->"),scanf("%s",key)!= EOF){
		if((p = search(root,key))!= NULL)
			printf("%s 找到了\n",p->name);
		else
			printf("Not found\n");
	}

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

struct tnode *search(struct tnode *p, char *key){
	if(p == NULL || strcmp(key,p->name) == 0)
		return p;
	if(strcmp(key,p->name) < 0)
		return search(p->left,key)
	else
		return search(p->right,key)
}
