#include <stdio.h>
#define max(a, b) a < b ? a : b

int maxDQ(int v[], int ini, int fim){
    int m, a, b;
    if ((fim - ini) <= 1)
        return max(v[ini], v[fim]);
    else{
    m = (ini + fim) / 2;
    a = maxDQ(v, ini, m);
    b = maxDQ(v, m + 1, fim);
    }
    return max(a, b);
}

int main(){
    int v[] = {10, -1 , 2, 55, 1, -2, -3, 4, 6, -9,0};
    printf("%d\n", maxDQ(v, 0, 10));
    return 0;
}
