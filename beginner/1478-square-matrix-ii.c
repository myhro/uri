#include <stdio.h>

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
                if (j >= i) {
                    printf("%*d", 3, (j - i) + 1);
                } else {
                    printf("%*d", 3, (i - j) + 1);
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
