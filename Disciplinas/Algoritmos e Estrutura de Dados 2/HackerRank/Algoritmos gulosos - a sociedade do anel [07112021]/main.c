#include <stdio.h>
#include <stdlib.h>


int metodoGuloso(int l, int c, int M[l][c])
{
    int i,j, a = 0;
    i=4;
    j=2;
    int posPrev[2]= {l,c};
        for(a=0; a<4; a++){
            //mapeamento da posição
            if(a == 0){i--;}
            if(a == 1){i++;j--;}
            if(a == 2){j+=2;}
            if(a == 3){i++;j--;}

            if(i>=0 && i<=5 && j>=0 && j<=5){
                printf("%d%d: [%d]\n",i, j, M[i][j]);
            }
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
