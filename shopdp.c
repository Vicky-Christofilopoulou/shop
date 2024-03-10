#include <stdio.h>
#include <stdlib.h>

int shop(int m, int n, int *k, int **c){
    int i,j,p;
    int **dp;
    dp= malloc((n)* sizeof(int * ));
    if (dp == NULL){
        return -1;
    }
    for (i=0; i<n; i++){
       *(dp+i)=malloc((m+1) * sizeof(int));
       if (*(dp+i)==NULL){
            return -1;
        }
    }
    for (i=0; i<n; i++){
        for (j=0; j<m+1; j++){
           dp[i][j]=0;   /*initialize the table with 0*/
        }
    }
    for (i=0; i<n; i++){
        if (i==0){ /*First line of the table*/
            for (j=0; j<k[i]; j++){ 
                if (m-c[i][j]>=0){
                    dp[i][m-c[i][j]]=1;
                }
            }
        }
        else{
            for (j=0; j<k[i]; j++){ /*Options for product i*/
                for(p=0; p<m+1; p++){ /* Check every square of the table if it's 1*/
                    if (dp[i-1][p] == 1 && (p-c[i][j]) >= 0) {/* if there is an 1 in the above line and j collumυm*/
                        dp[i][p-c[i][j]]=1;
                    }
                }
            }
        }
    }
    for (j=0; j<m+1; j++){ /*The first 1 in the last line is the solution. No 1 -> no solution*/
        if (dp[n-1][j]==1){
            break;
        }
    }
    if (j==m+1){
        printf("No solution found\n");
    }
    else{
        printf("Maximum amount spent is:%d\n",m-j);
    }
    for(i=0; i<n; i++){
        free (dp[i]);
    }
    free(dp);
    return 0;
}