#include <stdio.h>
#include <stdlib.h>

int metodoGuloso(int l, int c, int M[l][c]){
    int i,j;
    int pos = M[0][0];
    int v[4] = {0,0,0,0};
}

int main()
{
    int l, c, i, j;
    scanf("%d %d", &l, &c);
    int M[l][c];
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            scanf("%d", &M[i][j]);
        }
    }
    metodoGuloso(l,c,M);
}
