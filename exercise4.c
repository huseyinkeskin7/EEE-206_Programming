#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	float width,height;
	float area;
	
	printf("Write width and height values respectively(After write a every grade press enter):\n");
	scanf("%f",&width);
	scanf("%f",&height);
	
	area=height*width;
	printf("Area is %.2f",area);
	
	return 0;
}
