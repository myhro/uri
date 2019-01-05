#include <stdio.h>

int main() {
    int a;
    int b;
    int c;
    int d;
    int prod1;
    int prod2;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);

    prod1 = a * b;
    prod2 = c * d;

    printf("DIFERENCA = %d\n", prod1 - prod2);

    return 0;
}
