#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int divisaoEConquista(int * v1, int * v2, int ini, int fim){
    
    int mid, dist=0;
    if(fim == ini){

        dist = abs(v1[ini] - v2[fim]);
        return  dist;
    }
    else{
        mid = (fim + ini)/2;
        dist = divisaoEConquista(v1, v2, ini, mid) + divisaoEConquista(v1, v2, mid+1, fim);
    }
    
    return dist;
   
}

int main(){
    int N, i;
    scanf("%d", &N);

    int v1[N], v2[N];

    for (i = 0; i < N; i++){
        scanf("%d", &v1[i]);
    }
    
     for (i = 0; i < N; i++){
        scanf("%d", &v2[i]);
    }


    printf("%d", divisaoEConquista(v1, v2, 0, N));  

}