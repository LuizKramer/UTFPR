

typedef struct Cell Cell;
typedef struct Lista Lista;
typedef struct GrafoLA GrafoLA;
typedef struct FilaE FilaE;

struct GrafoLA{
   int V;
   int A;
    int *cor;
    int *pai;
    int *d;
   Lista **adj;
};

struct FilaE{
    Cell *inicio;
    Cell *fim;
};

struct Lista{
    Cell *head;
};

struct Cell{
    int key;
    struct Cell *next;
};