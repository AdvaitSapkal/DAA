#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

//utils
void print_matrix(int n,int mat[n][n]){
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(i>j)printf("         ");
            else printf(" %7d ",*(*(mat+i)+j));
        }
        printf(" \n");
    }

}

//constructing the solution
void print_optimal_parentheses(int n,int s[n][n],int i,int j){
    if(i==j){
        printf("A%d",i);
    }else{
        printf("(");
        print_optimal_parentheses(n,s,i,s[i][j]);
        print_optimal_parentheses(n,s,s[i][j]+1,j);
        printf(")");
    }
    
}

//computing the solution
void matrix_chain_multiplication(int dimensions[],int n){

    //initialization
    int m[n+1][n+1];
    int s[n+1][n+1];
    for(int i=0;i<n+1;i++){
        m[i][i]=0;
        s[i][i]=0;
    }

    //diagonal traversal
    int len=2;
    while(len<n+1){
        int second=len;
        int first=1;
        while(second<n+1){
            int min=INT_MAX;
            int mink=0;
            int k=first;
            while(k<second){
                int temp_cost=  m[first][k]
                              + m[k+1][second]
                              + dimensions[first-1]*dimensions[k]*dimensions[second];
                if(temp_cost<min){
                    min=temp_cost;
                    mink=k;
                }
                k++;
            }
            m[first][second]=min;
            s[first][second]=mink;
            first++;
            second++;
        }
        len++;
    }

    //printing results
    printf("\nthe cost matrix is: \n");
    print_matrix(n+1,m);
    printf("\nthe k matrix is: \n");
    print_matrix(n+1,s);

    printf("\noptimal cost is: %d\n",m[1][n]);

    printf("\noptimal parentheses is:\n\n");
    print_optimal_parentheses(n+1,s,1,n);
    printf(" \n");
}


int main(){
    int n;
    printf("enter number of matrices:\n");
    scanf("%d",&n);
    int dimensions[n+1];
    printf("enter dimension array:\n");
    for(int i=0;i<n+1;i++)scanf("%d",&dimensions[i]);
    matrix_chain_multiplication(dimensions,n);
}