#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int noye,noc;
	float total;
	
	printf("Write your number of years employed and number of children you have respectively(After write a every input press enter):\n");
	scanf("%d",&noye);
	scanf("%d",&noc);
	
	total=400+(noye*20)+(noc*30);
	printf("The total amount is %.1f$. 400$ minimum wage + %d$ for %d years experience + %d$ for %d kids",total,noye*20,noye,noc*30,noc);
	
	return 0;
}
