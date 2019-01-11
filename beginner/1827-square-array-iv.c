#include <stdio.h>

int main() {
    int diff;
    int half;
    int third;
    int i;
    int j;
    int n;

    while (scanf("%d", &n) != EOF) {
        half = n / 2;
        third = n / 3;
        diff = n - third;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if ((i == half) && (j == half)) {
                    printf("%d", 4);
                } else if ((i >= third) && (i < diff) && (j >= third) && (j < diff)) {
                    printf("%d", 1);
                } else if (i == j) {
                    printf("%d", 2);
                } else if ((n - j - 1) == i) {
                    printf("%d", 3);
                } else {
                    printf("%d", 0);
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
