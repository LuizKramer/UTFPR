#include <stdio.h>
#include <stdlib.h>


int metodoGuloso(int l, int c, int M[l][c])
{
    int i,j, a = 0;
    int aux=100;
    int iProx;
    int jProx;
    i=0;
    j=0;


    int posPrev[2]= {l,c};
    while(i!= l && j !=c){
        posPrev[0] = iProx;
        posPrev[1] = jProx;
        for(a=0; a<4; a++){
            //mapeamento da posição
            if(a == 0){i--;}
            if(a == 1){i++;j--;}
            if(a == 2){j+=2;}
            if(a == 3){i++;j--;}

            if(i>=0 && i<=5 && j>=0 && j<=5){
                printf("%d%d: [%d]\n",i, j, M[i][j]);
                if(i != posPrev[0] && j!= posPrev[2]){
                    if(M[i][j] <= aux){
                        aux = M[i][j];
                        iProx = i;
                        jProx = j;
                    }
                }
            }
        }

        i = iProx;
        j = jProx;
        printf("\nPROX %d%d\n", iProx, jProx);
    }
    return aux;
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
