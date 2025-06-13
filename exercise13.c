#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int hour,mem;
	float total,tax,pay;
	printf("How many hours you spend:");
	scanf("%d",&hour);
	
	printf("1- I am member\n2- I am not a member\nPlease enter with number:");
	scanf("%d",&mem);
	if(mem==1){
		pay=hour*2;
		tax = pay*10/100;
		total=pay+tax;
		printf("The user is a member stayed %d hours for 2$/hour plus the 10% the total amount is %.2f$",hour,total);
	}
	else if(mem==2){
		pay=hour*5;
		tax = pay*20/100;
		total=pay+tax;
		printf("The user is a member stayed %d hours for 5$/hour plus the 20% the total amount is %.2f$",hour,total);
	}
	else{
		printf("Incorrect choice");
		return 0;
	}
	
	
	return 0;
}
