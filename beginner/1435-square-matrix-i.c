#include <stdio.h>

int min(x, y) {
    if (x < y) {
        return x;
    }
    return y;
}

int main() {
    int i;
    int j;
    int n;

    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (j < (n - i)) {
                    printf("%*d", 3, min(i, j) + 1);
                } else {
                    printf("%*d", 3, min(n - i, n - j));
                }
                if (j != (n - 1)) {
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
