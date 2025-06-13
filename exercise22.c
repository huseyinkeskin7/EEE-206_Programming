#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int a1,i;


	i=0;
	for(i=0;i<5;i++){
	printf("Enter your any five number:(After entering every number, press the enter button)\n---->");
	scanf("%d",&a1);
	if(a1<0){
		printf("Negative\n");
	}
	else if(a1>0){
		printf("Positive\n");
	}
	
}
	return 0;
}
