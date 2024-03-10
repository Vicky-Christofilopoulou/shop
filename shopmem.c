#include <stdio.h>
#include <stdlib.h>

int R(int m, int n, int *k, int **c,int P,int i, int **MEM){
    if ((i==n) && (P>=0)){
        return P;
    }
    if ((i==n) && (P<0)){
        return m;
    }
    int j,x;
    int min=m+1;
    for (j=0; j< k[i]; j++){
        if (P>=0 && i>0 && MEM[i-1][P] != -1){  /*I have already calculate it*/
            return MEM[i-1][P];
        }
        else {
            x=R(m,n,k,c,P-c[i][j],i+1,MEM);
            if (P>=0){
                MEM[i][P]=x;
            } 
        }
        if (min > x){
            min=x;
        }

    }
    return min;
}

int shop(int m, int n, int *k, int **c){
    int i,j;
    int **MEM;
    MEM= malloc((n+1)* sizeof(int * ));
    if (MEM == NULL){
        return -1;
    }
    for (i=0; i < n+1; i++){
       *(MEM+i)=malloc((m+1) * sizeof(int));
       if (*(MEM+i)==NULL){
            return -1;
        }
        for (j=0; j<m+1; j++){
            MEM[i][j]=-1; /*initialize the table with an irrational number*/
        }
    }
    int Result=R(m,n,k,c,m,0,MEM);
    int s = m-Result;
    if (s==0){
        printf("No solution found\n");
    }
    else{
        printf("Maximum amount spent is:%d\n",s);
    }
    for(i=0; i<n+1; i++){
        free (MEM[i]);
    }
    free(MEM);
    return 0;
}