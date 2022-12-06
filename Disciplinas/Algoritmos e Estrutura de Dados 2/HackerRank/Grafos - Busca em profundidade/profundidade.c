#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

/***************************************************************/
typedef struct Cell Cell;
typedef struct Lista Lista;
typedef struct GrafoLA GrafoLA;
typedef struct GrafoMA GrafoMA;

struct Cell{
    int key;
    struct Cell *next;
};


struct GrafoMA{
    int V, A;
    int *cor;
    int *pai;
    int *d;
    int *f;
    int **mat;
};


struct Lista{
    Cell *head;
};

struct GrafoLA{
   int V;
   int A;
    int *cor;
    int *pai;
    int *d;
    int *f;
   Lista **adj;
};


static int** iniciar_MA(int n){
    int i, j;
    int **mat = (int**) malloc(n * sizeof(int*));

    for (i = 0; i < n; i++)
        mat[i] = (int*) calloc(n, sizeof(int));

    return mat;
}

GrafoMA* iniciar_grafoMA(int v){
    GrafoMA* G = (GrafoMA*) malloc(sizeof(GrafoMA));

    G->V = v;
    G->A = 0;
    G->cor = (int*) malloc(sizeof(int) * v);
    G->pai = (int*) malloc(sizeof(int) * v);
    G->d = (int*) malloc(sizeof(int) * v);
    G->f = (int*) malloc(sizeof(int) * v);
    G->mat = iniciar_MA(G->V);

    return G;
}


GrafoMA * LAtoMA(GrafoLA * LA){
    if(LA != NULL){
        int MA[LA->V][LA->V];
        Cell * aux;
        GrafoMA * GM = iniciar_grafoMA(LA->V);
        
        for(int i=0; i < LA->V; i++){
            for(int j=0; j < LA->V; j++){
                GM->mat[i][j] = 0;
            }
        }

        for(int i = 0; i < LA->V; i++){
            aux = LA->adj[i]->head;
            while (aux != NULL){
                  
                    
                    GM->mat[i][aux->key] = 1;
             
                    aux = aux->next;                
            }
     
        }
        
        return GM;
    }
    return NULL;
}

Lista* criar_lista(){
    Lista* l = (Lista*) malloc(sizeof(Lista));

    l->head = NULL;

    return l;
}


Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->key = key;

    c->next = NULL;

    return c;
}

int lista_vazia(Lista *l){
    return (l == NULL) || (l->head == NULL);
}


int procurar(int key, Lista *l){
    Cell *aux;

    if (l != NULL){
        aux = l->head;

        while ((aux != NULL) && (key < aux->key))
            aux = aux->next;
    }

    if ((aux != NULL) && (key == aux->key))
        return 1;
    else
        return 0;
}


void inserir_na_lista(int key, Lista *l){
    Cell *auxA, *auxP;
    Cell* c;

    if (lista_vazia(l)){
        if (l == NULL)
            l = criar_lista();

        l->head = criar_celula(key);
    }else{
        c = criar_celula(key);

        if (l->head->key >= key){
           c->next = l->head;


           l->head = c;
        }else{
            auxA = l->head;
            auxP = auxA;

            while ((auxP != NULL) && (auxP->key < key)){
                auxA = auxP;
                auxP = auxP->next;
            }

            auxA->next = c;
            c->next = auxP;
        }
    }
}


int remover_na_lista(int key, Lista *l){
    Cell *auxA, *auxP;

    if (!lista_vazia(l)){
        auxA = l->head;

        if(auxA->key == key)
            l->head = l->head->next;
        else{
            auxP = auxA;

            while((auxA != NULL) && (key < auxA->key)){
                auxP = auxA;
                auxA = auxA->next;
            }

            if (auxA->key == key)
            	auxP->next = auxA->next;
            else
            	auxA = NULL;
        }

        if (auxA != NULL)
            free(auxA);

        return 1;
    }

        return 0;
}


void imprimir(Lista *l){
    Cell *aux;

    if (!lista_vazia(l)){
        aux = l->head;

        while (aux != NULL){
            printf("%d\n", aux->key);

            aux = aux->next;
        }
    }
}


int liberar_lista(Lista *l){
    Cell *aux;

    if ((l != NULL) && !lista_vazia(l)){

        while(l->head != NULL){
            aux = l->head;

            l->head = aux->next;

            free(aux);
        }

        free(l);

        return 1;
    }

    return 0;
}


/***************************************************************/
// Grafo

static Lista** iniciar_LA(int n){
    int i;
    Lista **adj = (Lista**) malloc(n * sizeof(Lista*));

    for (i = 0; i < n; i++)
        adj[i] = criar_lista();

    return adj;
}


GrafoLA* iniciar_grafoLA(int v){
    GrafoLA* G = (GrafoLA*) malloc(sizeof(GrafoLA));

    G->V = v;
    G->A = 0;
    G->cor = (int*) malloc(sizeof(int) * v);
    G->pai = (int*) malloc(sizeof(int) * v);
    G->d = (int*) malloc(sizeof(int) * v);
    G->f = (int*) malloc(sizeof(int) * v);
    G->adj = iniciar_LA(G->V);

    return G;
}



int aresta_existeLA(GrafoLA* G, int v1, int v2){
    if ((G!= NULL) && (G->adj[v1]->head != NULL))
        return procurar(v2, G->adj[v1]);

    return 0;
}


void inserir_arestaLA(GrafoLA* G, int v1, int v2){
    if (!aresta_existeLA(G, v1, v2)){
        inserir_na_lista(v2, G->adj[v1]);
        inserir_na_lista(v1, G->adj[v2]);
        G->A++;
    }
}


void remover_arestaLA(GrafoLA* G, int v1, int v2){
    if (aresta_existeLA(G, v1, v2)){
        remover_na_lista(v2, G->adj[v1]);
        remover_na_lista(v1, G->adj[v2]);
        G->A--;

    }
}


 int** adjacentes(GrafoMA* grafo)
 {
     int i, j, k, tam;
     int **mat;

     tam = grafo->V;
     mat = (int**) malloc(sizeof(int*) * tam);

     for(i = 0; i < tam; i++)
     {
         mat[i] = (int*) calloc(tam, sizeof(int));
     }

     for(i = 0; i < tam; i++)
     {
         for(j = 0, k = 0; j < tam; j++)
         {
             if(grafo->mat[i][j] != 0)
             {
                 mat[i][k] = j + 1;
                 k++;
             }
         }
     }

     for(i = 0; i < tam; i++)
     {
         for(j = 0, k = 0; j < tam; j++)
         {
             printf("%d ", mat[i][j]);
         }

         printf("\n");
     }

    return mat;
 }

void imprimir_arestasLA(GrafoLA* G){
    int i;
    Cell *aux;

    if (G != NULL)
        for (i = 0; i < G->V; i++){
            aux = G->adj[i]->head;

            while (aux != NULL){
                printf("(%d, %d)\n", i, aux->key);

                aux = aux->next;
            }

        }
}

int buscaVertice(int i, int* cor, int tempo, int* d, int* f, int* pai, int** mat)
 {
     int j, k;

     cor[i] = 1;
     tempo = tempo + 1;
     d[i] = tempo;

     for(j = (mat[i][0] - 1), k = 0; mat[i][k] != 0; k++, j = (mat[i][k] - 1))
     {
         if(cor[j] == 0)
         {
             pai[j] = i;
             tempo = buscaVertice(j, cor, tempo, d, f, pai, mat);
         }
     }

     cor[i] = 2;
     f[i] = tempo = tempo + 1;

     return tempo;
 }

 void buscaLargura(GrafoMA* grafo)
 {
     int i, tam, tempo;
     int *cor, *pai, *d, *f;
     int **mat;

     tam = grafo->V;

     cor = (int*) malloc(sizeof(int) * tam);
     pai = (int*) malloc(sizeof(int) * tam);
     d = (int*) calloc(tam, sizeof(int));
     f = (int*) calloc(tam, sizeof(int));

     tempo = 0;
     mat = adjacentes(grafo);

     for(i = 0; i < tam; i++)
     {
        cor[i] = 0;
        pai[i] = INT_MAX;
     }

     for(i = 0; i < tam; i++)
     {
         if(cor[i] == 0)
         {
             buscaVertice(i, cor, tempo, d, f, pai, mat);
         }
     }

     printf("v d f p\n");

     for(i = 0; i < tam; i++)
     {
         printf("%d %d %d ", i, d[i], f[i]);

         if(pai[i] == INT_MAX)
         {
             printf("-\n");
         }
         else
         {
             printf("%d\n", pai[i]);
         }
     }
 }


int main(){
    int N, item;
    scanf("%d", &N);
    item = 0;
    GrafoLA * LA = iniciar_grafoLA(N);

    for(int i = 0; i < N; i++){
        do{
            scanf("%d", &item);
            if(item != -1)
                inserir_arestaLA(LA, i, item);
        }
        while(item != -1);
    }
    GrafoMA * GM = LAtoMA(LA);

    adjacentes(GM);
   
    
}
