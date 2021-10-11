#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool verificaPrev(int *v, int i, int j, int l, int c, int d){
    int x = (((i+1)*l+1)+((j-c)));
    for(int a=0; a<d; a++){
        if(x == v[a]){
            return 0;
        }
    }
    return 1;
}

int metodoGuloso(int l, int c, int M[l][c])
{
    if(l>c) // Requisito para funcionamento da formula
       c = c +(l - c);

    int i,j, a = 0;
    i=0;
    j=0;
    int d =0;
    int aux = 100;
    int posPrev[(l*c)];
    posPrev[0] = -1;
    int posNext[2];
    int indPosPrev =0;
    while(d != 10){
        printf("posAtual: %d%d\n", i, j);
        for(a=0; a<4; a++){
            //mapeamento da posição
            if(a == 0){i--;}
            if(a == 1){i++;j--;}
            if(a == 2){j+=2;}
            if(a == 3){i++;j--;}

            if(i>=0 && i<=5 && j>=0 && j<=5){
                printf("%d%d: [%d]\n",i, j, M[i][j]);
                if(M[i][j]<=aux){

                    if(verificaPrev(posPrev, i, j, l, c, d)){
                        aux = M[i][j];
                        posNext[0] = i;
                        posNext[1] = j;
                    }
                }
            }
        }
        i--;
        posPrev[d] = (((i+1)*l+1)+((j-c)));
        i = posNext[0];
        j = posNext[1];
        aux = 100;
        printf("\posPrev: %d\n", posPrev[d]);
        d++;
        printf("\n-------------------\n");
    }
    return 0;
}

int main()
{
    int l, c, i, j;
    scanf("%d %d", &l, &c);
    int M[l][c];
    for(i=0; i<l; i++){
        for(j=0; j<c; j++){
            scanf("%d", &M[i][j]);
        }
    }
    printf("\n%d", metodoGuloso(l,c,M));
}
