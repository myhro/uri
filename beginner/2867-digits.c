#include <math.h>
#include <stdio.h>

int main() {
    int c;
    int i;
    int m;
    int n;
    int r;

    while (scanf("%d", &c) != EOF) {
        for (i = 0; i < c; i++) {
            scanf("%d %d", &n, &m);
            r = m * log10(n) + 1;
            printf("%d\n", r);
        }
    }

    return 0;
}
