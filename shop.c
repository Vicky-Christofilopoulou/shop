/* Assigment 3: shop*/
#include <stdio.h>
#include <stdlib.h>
#include "shop.h"

int main (int argc, char *argv[]){
    int M,N,i,j;
    int *k;
    int **c;
    if (argc != 2) /*Wrong number of arguments*/
    {
        return 0;
    }
    M=atoi(argv[1]);
    scanf("%d", &N); /*The amount of products you want to buy*/
    k= malloc(N* sizeof(int));
    if (k == NULL){
        return -1;
    }
    c= malloc(N* sizeof(int * ));
    if (c == NULL){
        return -1;
    }
    for (i=0; i<N; i++){
       scanf("%d",&k[i]); /*obtainable options*/
       *(c+i)=malloc(k[i] * sizeof(int));
       if (*(c+i)==NULL){
            return -1;
        }
        for (j=0; j<k[i]; j++){
            scanf("%d", &c[i][j]); /*Value of the product*/
        }
    }
    shop(M,N,k,c);
    for(i=0; i<N; i++){
        free (c[i]);
    }
    free(k);
}