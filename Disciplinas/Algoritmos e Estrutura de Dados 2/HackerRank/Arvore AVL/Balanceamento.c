#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node Node;

struct Node{
	int item; // chave
    int fb;
	struct Node *left; // referência para a sub-árvore esquerda
	struct Node *right; // referência para a sub-árvore direita
};



Node* criar(int item){
	Node * tree = (Node *) malloc(sizeof(Node));

	tree->item = item;
    	tree->fb = 0;
	tree->left = NULL;
	tree->right = NULL;

	return tree;
}

static Node* rotateL(Node *tree){
	Node *auxA = tree->left, *auxB;

	if (auxA->fb == +1){
		tree->left = auxA->right;
		auxA->right = tree;
		tree->fb = 0;
		tree = auxA;
	}else{ 
		auxB = auxA->right;
		auxA->right = auxB->left;
		auxB->left = auxA;
		tree->left = auxB->right;
		auxB->right = tree;

		if (auxB->fb == +1)
			tree->fb = -1; 
		else
			tree->fb = 0; 

		if (auxB->fb == -1)
			auxA->fb = +1; 
		else
			auxA->fb = 0;

		tree = auxB;
	}
	
	return tree;
}



static Node* rotateR(Node *tree){
	Node *auxA = tree->right, *auxB;


	if (auxA->fb == -1){
		tree->right = auxA->left;
		auxA->left = tree;
		tree->fb = 0;
		tree = auxA;
	}else{ 
		auxB = auxA->left;
		auxA->left = auxB->right;
		auxB->right = auxA;
		tree->right = auxB->left;
		auxB->left = tree;

	
		if (auxB->fb == -1)
			tree->fb = +1; 
		else
			tree->fb = 0; 

		if (auxB-> fb == +1)
			auxA->fb = -1; 
		else
			auxA->fb = 0; 

		tree = auxB;
	}
	
	return tree;
}


//
Node* inserir(Node* tree, int value, int *grown){
	Node *auxA, *auxB;
    printf("a");
	if(tree == NULL){
		tree = criar(value);
		*grown = 1;

	}else if (value < tree->item){
		tree->left = inserir(tree->left, value, grown);

		if (*grown){ 
			switch (tree->fb){
				case -1: tree->fb = 0; *grown = 0; break; 
				case 0: tree->fb = +1; break;
				case +1: tree = rotateL(tree); tree->fb = 0; *grown = 0;
			}
		}
	}else if (value > tree->item){
		tree->right = inserir(tree->right, value, grown);

		if (*grown){
			switch (tree->fb){
				case +1: tree->fb = 0; *grown = 0; break;
				case 0: tree->fb = -1; break;
				case -1: tree = rotateR(tree); tree->fb = 0; *grown = 0;
			}
		}
	}

	return tree;
}

void imprimir(Node * tree){
    if(tree != NULL){
        imprimir(tree->left);
            printf("%d", tree->item);
        imprimir(tree->right);
    }
}

int main(){
    int N;
    scanf("%d", &N);
    int item;
    Node * tree = (Node*)malloc(sizeof(Node) * N);
    for(int i = 1; i < N; i++){
        scanf("%d", &item);
        inserir(tree, item,1);
    }
    imprimir(tree);
}