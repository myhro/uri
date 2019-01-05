#include <stdio.h>

int main() {
    char name[256];
    double salary;
    double sold;
    double total;

    scanf("%s", name);
    scanf("%lf", &salary);
    scanf("%lf", &sold);

    total = salary + (sold * 0.15);

    printf("TOTAL = R$ %.2f\n", total);

    return 0;
}
