#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

typedef struct Node Node;


Node* criar(int item);

Node* inserir(int item, Node* tree);

void liberar_arvore(Node* tree);


struct Node{
	int item; 
	struct Node *left; 
	struct Node *right; 
};



Node* criar(int item){
	Node * tree = (Node *) malloc(sizeof(Node));
	
	tree->item = item;
	tree->left = NULL;
	tree->right = NULL;
		
	return tree;
}



Node* inserir(int item, Node* tree){

	if (tree == NULL)
		tree = criar(item);

	else if (item < tree->item)
		tree->left = inserir(item, tree->left);

	else if (item > tree->item)
		tree->right = inserir(item, tree->right);
		
	return tree;
}


void liberar_arvore(Node* tree){
    if (tree != NULL){
        liberar_arvore(tree->left);
        liberar_arvore(tree->right);
        free(tree);
    }
}

int altura(Node * tree){
    if(tree == NULL){
        return 0;
    }
   
    int left = altura(tree->left);
    int right = altura(tree->right);

    return left > right? left +1 : right + 1; 

}

int qtd_itens(Node * tree){
    
    if(tree == NULL){
        return 0;
    }
    
   return 1 + (qtd_itens(tree->left) + qtd_itens(tree->right));  
}

int nos_faltantes(Node * tree){
    return pow(2, altura(tree)) - qtd_itens(tree) - 1;
}

int main(){
    int item, N;
       
    scanf("%d", &N);
    scanf("%d", &item);
    Node * tree = criar(item);
    for(int i = 0; i<N-1; i++){
         scanf("%d", &item);
         inserir(item, tree); 
    }
    printf("%d", nos_faltantes(tree));
   
    liberar_arvore(tree);
}