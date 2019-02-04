#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

void triangle(int a, int b, int c) {
    if (a >= (b + c)) {
        printf("Invalido\n");
        return;
    }
    
    if ((a != b) && (b != c)) {
        printf("Valido-Escaleno\n");
    } else if ((a == b) && (b == c)) {
        printf("Valido-Equilatero\n");
    } else if ((a == b) || (a == c) || (b == c)) {
        printf("Valido-Isoceles\n");
    }

    if (pow(a,2) == (pow(b,2) + pow(c, 2))) {
        printf("Retangulo: S\n");
    } else {
        printf("Retangulo: N\n");
    }
}

int main() {
    int list[3];
    int i;

    for (i = 0; i < 3; i++) {
        scanf("%d", &list[i]);
    }
    qsort(list, 3, sizeof(int), compare);
    triangle(list[2], list[1], list[0]);

    return 0;
}
