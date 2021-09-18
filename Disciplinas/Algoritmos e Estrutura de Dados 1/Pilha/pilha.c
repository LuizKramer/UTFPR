#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Declara��o de cada n� que cont�m os dados referenciados
typedef struct Node
{
    char data;
    struct Node * next;
} Node;
// Declara��o da estrutura que aponta para o topo e registra o tamanho da pilha
typedef struct
{
    Node * topo;
    int size;
} Pilha;
// Fun��o para criar a pilha com aloca��o dinamica


Pilha * CreateP()
{
    Pilha* P = (Pilha*) malloc(sizeof(Pilha));

    P->topo = NULL;
    P->size = 0;
    return P;
}
// Fun��o para criar o n� com aloca��o dinamica
Node * CreateN()
{
    Node * N = (Node*) malloc(sizeof(Node));
    N->data = '*';
    return N;
}
// Fun��o para inserir os dados no topo da pilha
void Push (Pilha * P, char a)
{
    Node * N = CreateN();
    N->data = a;
    N->next = P->topo;
    P->topo = N;
    P->size++;
}
// Fun��o para imprimir toda a pilha
void imprimir(Pilha * P)
{
    Node * ptr;
    ptr = P->topo;
    while(ptr != NULL)
    {
        printf("%c", ptr->data);
        ptr = ptr->next;
    }

}
// Fun��o para retirar o n� no topo da pilha
void Desempilhar(Pilha * P)
{
    Node * ptr = CreateN();
    ptr = P->topo;
    P->topo = ptr->next;
    free(ptr);
    P->size--;
}
// Fun��o para Destruir a pilha
void KillPilha(Pilha * P){

    while(P->topo != NULL){
        Desempilhar(P);
    }

}

int main()
{
    Pilha * P1;
    P1 = CreateP();
    //Inser��o da palavra "teste" na pilha
    Push(P1, 'e');
    Push(P1, 't');
    Push(P1, 's');
    Push(P1, 'e');
    Push(P1, 't');
    imprimir(P1);
    printf("\n");
    // Retirada do topo da pilha
    Desempilhar(P1);
    imprimir(P1);
    // Destrui��o da pilha
    KillPilha(P1);
    printf("\nA pilha foi destruida");

}
