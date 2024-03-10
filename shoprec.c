#include <stdio.h>

int R(int m, int n, int *k, int **c,int P,int i){
    if ((i==n) && (P>=0)){
        return P;
    }
    if ((i==n) && (P<0)){
        return m;
    }
    int j,x;
    int min=m+1;
    for (j=0; j< k[i]; j++){
        x=R(m,n,k,c,P-c[i][j],i+1);
        if (min > x){
            min=x;
        }
    }
    return min;
}

int shop(int m, int n, int *k, int **c){
    int Result=R(m,n,k,c,m,0);
    int s = m-Result;
    if (s==0){
        printf("No solution found\n");
    }
    else{
        printf("Maximum amount spent is:%d\n",s);
    }
    return 0;
}