#include <stdio.h>
#include <string.h>
#define List 20

int main() {
    char names[List][30];
    int salaries[List],noe = 0,total = 0;

    while (1) {
        printf("Enter name and salary (After enter the name press enter and enter the salary)(press 0 to exit): ");
        char name[50];
        int salary;
        scanf("%s", name);
        if (strcmp(name, "0") == 0) {
            break;
        }
        scanf("%d", &salary);
        strcpy(names[noe], name);
        salaries[noe] = salary;
        total=total+salary;
		noe++;
    }
    printf("%d employees and the total amount of salaries is %d$\n", noe, total);

return 0;
}
