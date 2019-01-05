#include <stdio.h>

#define PRODUCTS 2

int main() {
    int code[PRODUCTS];
    int units[PRODUCTS];
    float price[PRODUCTS];
    float total = 0;
    int i;

    for (i = 0; i < PRODUCTS; i++) {
        scanf("%d %d %f", &code[i], &units[i], &price[i]);
        total += units[i] * price[i];
    }

    printf("VALOR A PAGAR: R$ %.2f\n", total);

    return 0;
}
