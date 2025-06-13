#include <stdio.h>

void pstars(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int num_stars;
    printf("Enter the number of stars: ");
    scanf("%d", &num_stars);

    pstars(num_stars);

return 0;
}
