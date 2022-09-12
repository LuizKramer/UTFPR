#include <stdio.h>
#include <stdlib.h>

int divisaoEConquista(int * v1, int * v2, int ini, int fim){
    int mid;
    if((fim - ini) <= 1){
         return v1[ini];
    }
    else{
    printf("\n");

    mid = (fim - ini)/2;
  
        printf("primeira: %d\n", divisaoEConquista(v1, v2, ini, mid));
    printf("\n------------\n");
        printf("segunda: %d\n", divisaoEConquista(v1, v2, mid+1, fim));
    }
   
   

   
    
}

int main(){
    int N;
    scanf("%d", &N);
    int v1[N], v2[N];

    for (int i = 0; i < N; i++){
        scanf("%d %d", &v1[i], &v2[i]);
    }


    divisaoEConquista(v1, v2, 0, N);
  

}