#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int geo,alg,phy;
	int average;
	
	printf("Write your geometry, algebra, and physics grades respectively(After write a every grade press enter):\n");
	scanf("%d",&geo);
	scanf("%d",&alg);
	scanf("%d",&phy);
	
	average=(geo+alg+phy)/3;
	printf("Average is %d",average);
	
	return 0;
}
