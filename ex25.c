#include <stdio.h>
#include <stdlib.h>

int main() {
	float per_heads,per_tails;
	char inp[7];
	int heads = 0, tails = 0, count = 0;
	
	while(1){
		printf("Enter the flipped coin was heads or tails\n----->");
		scanf("%s",inp);
		if(strstr(inp, "heads") != NULL){
		heads++;
		count++;
		}
		else if(strstr(inp, "tails") != NULL){
		tails++;
		count++;
		}
		else if(strstr(inp, "stop") != NULL){
			break;
		}
		else {
            printf("Invalid input\n");
            continue;
        }

	}
	per_heads=heads/count*100;
	per_tails=tails/count*100;
	printf("Head won %d times and tails won %d times\n", heads, tails);
	printf("%.2f % Head, %.2f % Tails\n", per_heads, per_tails);
	return 0;
}
