#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int sec;
	float pay;
	printf("Print how many seconds was the calls duration:");
	scanf("%d",&sec);
	
	if(sec<=500&&sec>=1){
		pay=sec*0.01;
		printf("Total amount is %.2f$",pay);
	}
	else if(sec<=800&&sec>=501){
		pay=sec*0.008;
		printf("Total amount is %.3f$",pay);
	}
	else if(sec>=801){
		pay=sec*0.005;
		printf("Total amount is %.3f$",pay);
	}
	else{
		printf("Incorrect choice");
		return 0;
	}
	
	
	return 0;
}
