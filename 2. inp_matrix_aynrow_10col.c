#include <stdio.h>

void funct(){
    int x;
    printf("Write number of rows: ");
    scanf("%d",&x);
    
    int matris[10][x];
    int i,j;
    
    for(i=0;i<10;i++){
        for(j=0;j<x;j++){
            scanf("%d",&matris[i][j]);
        }
    }
    
    for(i=0;i<10;i++){
        for(j=0;j<x;j++){
            printf("%d",matris[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}

int main()
{

    funct();
    
    return 0;
}