#include <stdio.h>

void funct(){
    int matris[10][10];
    int i,j;
    
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            scanf("%d",&matris[i][j]);
        }
    }
    
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
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
