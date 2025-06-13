#include <stdio.h>

int main() {
    int apart[20];
    int price;
    int a;
    int i = 0;
    float avrg , total;

    do {
        printf("Enter price %d(Enter 0 or negative value to finish):\n------>", i+1);
        scanf("%d", &price);
        if (price > 0) {
            apart[i] = price;
            total = total+price;
            i++;
        }
    } while (price > 0);

   
    if (i > 0) {
        avrg = total / i;
        printf("%d apartments have registered. The average price for rent is %.1f$\n", i, avrg);

        
        for (int a = 0; a < i; a++)  {
            if (apart[a] > avrg) {
                printf("Apartment %d is above average price\n", a+1);
            } else {
                printf("Apartment %d is below average price\n", a+1);
            }
        }
    } else {
        printf("No apartments registered\n");
    }

    return 0;
}
