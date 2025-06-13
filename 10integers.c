
#include <stdio.h>

int main()
{
int i,num;
int array[10];
    for(i=0;i<=9;i++){
        printf("Enter the number: ");
        scanf("%d",&num);
        array[i]=num;
    }
    printf("\nYou can see the numbers below\n");
    for(i=0;i<=9;i++){
        printf("%d",array[i]);
        printf("\n");
    }
    
    return 0;
}
