#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node Node;


Node* criar(int item);

Node* inserir(int item, Node* tree);

void liberar_arvore(Node* tree);

Node * nos_folhas(Node * tree);

struct Node{
	int item; // chave
	struct Node *left; // referência para a sub-árvore esquerda
	struct Node *right; // referência para a sub-árvore direita
};


// criar nó
Node* criar(int item){
	Node * tree = (Node *) malloc(sizeof(Node));
	
	tree->item = item;
	tree->left = NULL;
	tree->right = NULL;
		
	return tree;
}


// inserir um novo elemento na árvore
Node* inserir(int item, Node* tree){
	// se o nó é nulo, basta criar um novo
	if (tree == NULL)
		tree = criar(item);
	// Se o valor do nó for maior que o do item a ser inserido,
	// uma chamada recursiva para a sub-árvore esquerda é
	// chamada
	else if (item < tree->item)
		tree->left = inserir(item, tree->left);
	// Se o valor do nó for menor que o do item a ser inserido,
	// uma chamada recursiva para a sub-árvore direita é
	// chamada
	else if (item > tree->item)
		tree->right = inserir(item, tree->right);
		
	return tree;
}




// Desalocar todos os nós da árvore
void liberar_arvore(Node* tree){
    if (tree != NULL){
        liberar_arvore(tree->left);
        liberar_arvore(tree->right);
        free(tree);
    }
}

Node * nos_folhas(Node * tree){
    if(tree == NULL){
        return;
    }
    if(tree->left == NULL && tree->right == NULL){
        printf("%d ", tree->item);
    }
    nos_folhas(tree->left);
    nos_folhas(tree->right);

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
    nos_folhas(tree);
    liberar_arvore(tree);
}