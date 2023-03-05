//strassens matrix multiplication algorithm demo
#include<stdio.h>

//for printing a 2 x 2 matrix
void print_matrix(int mat1[2][2]){
    for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
        printf(" %3d",mat1[i][j]);
     }
        printf(" \n");
    }
}

int main(){

    //initializing
    int A[2][2]={    {1,3},
                     {7,5}   };
                        
    int B[2][2]={    {6,8},
                     {4,2}   };

    //display
    print_matrix(A);   printf("  X\n");   print_matrix(B);

    //sum matrices from sub matrices
    int S[11];
    S[ 1]=B[0][1]-B[1][1];  S[ 6]=B[0][0]+B[1][1];
    S[ 2]=A[0][0]+A[0][1];  S[ 7]=A[0][1]-A[1][1];
    S[ 3]=A[1][0]+A[1][1];  S[ 8]=B[1][0]+B[1][1];
    S[ 4]=B[1][0]-B[0][0];  S[ 9]=A[0][0]-A[1][0];
    S[ 5]=A[0][0]+A[1][1];  S[10]=B[0][0]+B[0][1];
    
    //product matrices from sum matrices
    int P[8];
    P[1]=A[0][0]*S[1];    P[5]=S[5]*S[6];
    P[2]=B[1][1]*S[2];    P[6]=S[7]*S[8];
    P[3]=B[0][0]*S[3];    P[7]=S[9]*S[10];
    P[4]=A[1][1]*S[4];

    //final matrices from product matrices
    int ret[2][2];
    ret[0][0]=P[5]+P[4]-P[2]+P[6];
    ret[0][1]=P[1]+P[2];
    ret[1][0]=P[3]+P[4];
    ret[1][1]=P[1]+P[5]-P[3]-P[7];

    //display
    printf("  =\n");
    print_matrix(ret);

}
