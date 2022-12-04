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
typedef struct FilaE FilaE;

struct FilaE{
    Cell *inicio;
    Cell *fim;
};


struct Cell{
    int key;
    struct Cell *next;
};


struct Lista{
    Cell *head;
};

struct GrafoLA{
   int V;
   int A;
   Lista **adj;
};

struct GrafoMA{
   int V;
   int A;
   int *nafila;
    int *pai;
    int *key;
   int ** mat;
};

Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->key = key;

    c->next = NULL;

    return c;
}

FilaE* criar_filaE(){
    FilaE *f = (FilaE*) malloc(sizeof(FilaE));
    
    f->inicio = NULL;
    f->fim = NULL;
    
    return f;
}

int filaE_vazia(FilaE* f){
    return (f == NULL) || (f->inicio == NULL);
}


void enfileirar(int key, FilaE* f){
    Cell *aux;

    if (f == NULL)
        f = criar_filaE();

    aux = criar_celula(key);

    if (f->inicio == NULL)
        f->inicio = f->fim = aux;
    else{
        f->fim->next = aux;
        f->fim = f->fim->next;
    }

}

int desenfileirar(FilaE* f){
    Cell *aux;
    int item = INT_MIN;

    if (!filaE_vazia(f)){
        aux = f->inicio;

        f->inicio = aux->next;
        
        item = aux->key;

        free(aux);
    }

    return item;
}

static int extract_min(FilaE *f, GrafoMA *g){
    int vM;
    Cell *aux, *auxM;
    
    auxM = f->inicio;
    aux = auxM->next;
    
    while (aux != NULL){
        if (g->key[aux->key] < g->key[auxM->key])
            auxM = aux;
        
        aux = aux->next;
    }
    
    if (auxM != f->inicio){
        vM = f->inicio->key;
        f->inicio->key = auxM->key;
        auxM->key = vM;
    }
    
    return desenfileirar(f);
}

int liberar_filaE(FilaE* f){
    if (!filaE_vazia(f)){
        while (f->inicio != NULL)
            desenfileirar(f);

        free(f);

        return 1;
    }

    return 0;
}

static int valida_vertice(GrafoMA* G, int v){
    return (v >= 0) && (v < G->V);
}

void imprimir_fila(FilaE* f){
    Cell *aux;

    if (!filaE_vazia(f)){
        aux = f->inicio;

        while (aux != NULL){
            printf("%d ", aux->key);
            aux = aux->next;
        }
        
        printf("\n");
    }
}


/***************************************************************/
// Lista encadeada

Lista* criar_lista(){
    Lista* l = (Lista*) malloc(sizeof(Lista));

    l->head = NULL;

    return l;
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

static int** iniciar_MA(int n){
    int i, j;
    int **mat = (int**) malloc(n * sizeof(int*));

    for (i = 0; i < n; i++)
        mat[i] = (int*) calloc(n, sizeof(int));

    return mat;
}


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
    G->adj = iniciar_LA(G->V);

    return G;
}

GrafoMA* iniciar_grafoMA(int v){
    GrafoMA* G = (GrafoMA*) malloc(sizeof(GrafoMA));

    G->V = v;
    G->A = 0;
     G->nafila = (int*) malloc(sizeof(int) * v);
    G->pai = (int*) malloc(sizeof(int) * v);
    G->key = (int*) malloc(sizeof(int) * v);
    G->mat = iniciar_MA(G->V);

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
       // inserir_na_lista(v1, G->adj[v2]);
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


void liberarGLA(GrafoLA* G){
    int i;

    if (G != NULL){
        for (i = 0; i < G->V; i++)
            liberar_lista(G->adj[i]);

        free(G);
    }
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


void Dijkstra(GrafoMA *G, int s,int N,  int peso[][N], int vertices){
    int u, v;
    FilaE *f = criar_filaE();
    
    if (valida_vertice(G, s)){
        for (v = 0; v < G->V; v++){
            G->pai[v] = -1;
            G->key[v] = INT_MAX;
            G->nafila[v] = 1;
            enfileirar(v, f);
        }
        
        G->key[s] = 0;
        while (!filaE_vazia(f)){
            u = extract_min(f, G);
            G->nafila[u] = 0;
            for (v = 0; v < G->V; v++){
                if ((G->mat[u][v] != 0) && (G->nafila[v]) && (G->key[s] + peso[u][v] < G->key[v])){
                    G->key[v] = G->key[s] + peso[u][v];
                    G->pai[v] = u;
                }
            }
        }
        
        for (v = 0; v < vertices; v++){
            printf("%d: ", v);

            if (G->pai[v] >= 0)
                printf("%d\n", G->pai[v]);
            else
                printf("-\n");
        }
        
        liberar_filaE(f);
    }
}


int main(){
    int N, v1, v2;
    int vertices;
    scanf("%d", &vertices);
    scanf("%d", &N);
    int peso[N][N];
    GrafoLA * LA = iniciar_grafoLA(N);
    int aux;
    for (int i =0; i <N ; i++){
        for(int j=0; j<N; j++){
            peso[i][j]= INT_MAX;
        }
    }
    for(int i = 0; i < N; i++){
        scanf("%d %d %d", &v1, &v2, &aux);
        peso[v1][v2] = aux;
        inserir_arestaLA(LA, v1, v2);
    }
    GrafoMA * MA = LAtoMA(LA);
    Dijkstra(MA,0,N, peso, vertices);

    
}