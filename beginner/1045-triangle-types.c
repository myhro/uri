#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(double *) a - *(double *) b;
}

void triangle(double a, double b, double c) {
    if (a >= (b + c)) {
        printf("NAO FORMA TRIANGULO\n");
        return;
    } if (pow(a,2) == (pow(b,2) + pow(c, 2))) {
        printf("TRIANGULO RETANGULO\n");
    } if (pow(a,2) > (pow(b,2) + pow(c, 2))) {
        printf("TRIANGULO OBTUSANGULO\n");
    } if (pow(a,2) < (pow(b,2) + pow(c, 2))) {
        printf("TRIANGULO ACUTANGULO\n");
    } if ((a == b) && (b == c)) {
        printf("TRIANGULO EQUILATERO\n");
        return;
    } if ((a == b) || (a == c) || (b == c)) {
        printf("TRIANGULO ISOSCELES\n");
    }
}

int main() {
    double list[3];
    int i;

    for (i = 0; i < 3; i++) {
        scanf("%lf", &list[i]);
    }
    qsort(list, 3, sizeof(double), compare);

    triangle(list[2], list[1], list[0]);

    return 0;
}
