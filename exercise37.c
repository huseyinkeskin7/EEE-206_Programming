#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[15];
    int salary;
} Employee;

int main() {
    Employee employees[] = {
        {"Mary", 32343},
        {"John", 12134},
        {"George", 25342},
        {"Nicole", 35342},
        {"Nick", 42343},
        {"Jim", 32134},
        {"Jack", 15342},
        {"Johanna", 25342}
    };

    int numberEmployees = sizeof(employees) / sizeof(employees[0]);

for (int i = 0; i < numberEmployees - 1; i++) {
        for (int j = 0; j < numberEmployees - i - 1; j++) {
            if (employees[j].salary > employees[j+1].salary) {
                Employee temp = employees[j];
                employees[j] = employees[j+1];
                employees[j+1] = temp;
            }
        }
    }

    printf("Employees in order by lowest salary first:\n");
    for (int i = 0; i < numberEmployees; i++) {
        printf("%s: %d\n", employees[i].name, employees[i].salary);
    }

    return 0;
}

