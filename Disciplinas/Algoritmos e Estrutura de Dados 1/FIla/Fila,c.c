#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

typedef struct
{
    Node* head;
    int size;
} Lista;

Lista * CreateL()
{
    Lista *L;
    L =(Lista*) malloc(sizeof(Lista));
    L->head = NULL;
    L->size = 0;
    return L;
}
Node * CreateN()
{
    Node * Key = (Node*) malloc(sizeof(Node));
    Key ->data = 0;
    Key -> next = NULL;
    return Key;
}
void Push(Lista* L, int data)
{
    Node* aux = CreateN();
    aux->data = data;
    aux->next = L->head;
    L->head = aux;
    L->size++;

}
Lista * Preencher(Lista* L)
{
    int n;
    while(n != -1)
    {
        scanf("%d", &n);
        if(n != -1)
        {
            Push(L, n);
        }
    }
    return L;
}

void Imprimir(Lista* L)
{
    Node* ptr;
    ptr = L->head;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

Lista * intercalar(Lista* L1, Lista* L2)
{
    int a;
    Node *ptr1;
    Node *ptr2;
    Node aux;
    Lista* L3;
    L3 = CreateL();
    ptr1 = L1->head;
    ptr2 = L2->head;
    if((L1->size)>(L2->size))
    {
        for(a=0; a< ((L1->size)-(L2->size)); a ++ )
        {
            Push(L3, ptr1->data);
            ptr1 = ptr1->next;
        }
        while((ptr1 != NULL) && (ptr2 != NULL))
        {
            if(ptr2 != NULL)
            {
                Push(L3, ptr2->data);
            }
            ptr2 = ptr2->next;
            if(ptr1 != NULL)
            {
                Push(L3,ptr1->data);
            }
            ptr1 = ptr1->next;
        }
    }
    else if ((L2->size)> (L1->size))
    {
        for(a=0; a< ((L2->size)-(L1->size)); a ++ )
        {
            Push(L3, ptr2->data);
            ptr2 = ptr2->next;
        }
        while((ptr2 != NULL) && (ptr1 != NULL))
        {
            if(ptr2 != NULL)
            {
                Push(L3, ptr2->data);
            }
            ptr2 = ptr2->next;
            if(ptr1 != NULL)
            {
                Push(L3,ptr1->data);
            }
            ptr1 = ptr1->next;
        }

    }
    else
    {
        while((ptr2 != NULL) && (ptr1 != NULL))
        {
            if(ptr2 != NULL)
            {
                Push(L3, ptr2->data);
            }
            ptr2 = ptr2->next;

            if(ptr1 != NULL)
            {
                Push(L3,ptr1->data);
            }
            ptr1 = ptr1->next;
        }
    }
    return L3;


}
Node * atPos(Lista * L, int index)
{
    Node * N = L->head;
    int i;
    for(i=0; i<index; i++)
    {
        N = N->next;
    }
    return N;

}

void erase(Lista * L, int index)
{
    Node * atual = atPos(L, index);
    Node * antes = atPos(L, index-1);

    if(atual != NULL){
    antes->next = atual->next;
    free(atual);
    }


}


void ClearR(Lista * L)
{
    Node *p1, *p2, *p3;
    int i,j;
    p1 = L->head;
    p2 = p3 = p1;
    i=1;
    j=1;
    while(p1 != NULL)
    {
        while(p2!=NULL)
        {
            p2 = p2->next;

            if(p2 != NULL)
            {

                if(p1->data == p2->data)
                {
                    erase(L, i);
                }
                i++;
            }


        }
        j++;
        i=j;
        p1 = p1->next;
        p2 = p1;
    }


}





int main()
{
    Lista *L1;
    Lista *L2;
    Lista *L3;
    int N, a;
    scanf("%d", &N);
    for(a=0; a<N; a++){
    L1 = CreateL();
    L1 = Preencher(L1);
    L2 = CreateL();
    L2 = Preencher(L2);
    L3 = intercalar(L1,L2);
    ClearR(L3);
    Imprimir(L3);
    printf("\n");
    }





}
