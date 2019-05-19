#include <stdio.h>

int main() {
    int diff;
    int pages;
    int res;
    int d;
    int p;
    int q;

    while (scanf("%d %d %d", &q, &d, &p) != EOF) {
        if (q == 0) {
            break;
        }

        res = q * d * p;
        diff = p - q;
        pages = res / diff;

        if (pages == 1) {
            printf("1 pagina\n");
        } else {
            printf("%d paginas\n", pages);
        }
    }

    return 0;
}
