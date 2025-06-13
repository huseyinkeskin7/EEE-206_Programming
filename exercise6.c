#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int price,tax;
	float total;
	
	printf("Write price and tax values respectively(After write a every grade press enter):\n");
	scanf("%d",&price);
	scanf("%d",&tax);
	
	total=price+(price*tax/100);
	printf("The total price is %.2f",total);
	
	return 0;
}
