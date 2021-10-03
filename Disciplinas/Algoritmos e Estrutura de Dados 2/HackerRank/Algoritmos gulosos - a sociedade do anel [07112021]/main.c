#include <stdio.h>
#include <stdlib.h>

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
     for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}
