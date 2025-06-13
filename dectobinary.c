
#include <stdio.h>

void decimal2binary(int dec, int array[]) {
    int index=0;
    while (dec>0) {
        array[index]= dec % 2;
        dec = dec/2;
        index++;
    }
}

int main()
{
    int dec;
    int array[32];
    int index=0;
    
    printf("Enter Decimal: ");
    scanf("%d",&dec);
    
    decimal2binary(dec,array);
    
    printf("Binary is: %d",dec);
    
    for(int i = index-1;i>=0; i--){
        printf("%d",array[i]);
    } 
    printf("\n");
    
    return 0;
}
