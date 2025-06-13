#include <stdio.h>

void matr(int matrix[][4],int size){
    int i,j;
    for(i=0;i<size;i++){
        for(j=0;j<4;j++){
            printf("%d",matrix[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}

int main()
{
    int x;
    printf("Write number of rows: ");
    scanf("%d",&x);
    
    int matrix[x][4];
    int i,j;
    
    printf("Write the matrix: ");
    for (i=0;i<x;i++){
        for (j=0;j<4;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    matr(matrix,x);
    
    return 0;
}

