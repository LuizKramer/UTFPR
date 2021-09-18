#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
} DataNode;

typedef struct Node
{
    DataNode Data;
    struct Node *next;
} Node ;

typedef struct
{
    int Size;
    Node *Head;

} Lista;

Lista * CreateList();
void push(Lista* lista, DataNode data);
void PrintList(Lista* lista);
Lista * LerLista (Lista* lista);


Lista * CreateList()
{
    Lista* aux = (Lista*) malloc(sizeof(Lista));
    aux->Head = NULL;
    aux->Size =0;
    return aux;
}

void push(Lista* lista, DataNode data)
{
    Node* node = (Node*) malloc(sizeof(Node));

    node->Data = data;
    node->next = lista->Head;
    lista->Head = node;
    lista->Size++;
}

void PrintList(Lista* lista)
{
    Node* ptr = lista->Head;
    while(ptr != NULL)
    {
        printf("%d ", ptr->Data.id);
        ptr = ptr->next;
    }
}

Lista * LerLista (Lista* lista)
{
    DataNode Data;
    while(Data.id != -1)
    {
        scanf("%d", &Data.id);
        if(Data.id != -1)
        {
            push(lista, Data);
        }
    }
    return lista;
}


int main()
{
}
