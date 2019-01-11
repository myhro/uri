#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {
    char max[256];
    int i;
    int j;
    int n;
    int t;

    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        sprintf(max, "%.0f", pow(2, 2 * (n - 1)));
        t = strlen(max);
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("%*.0f", t, pow(2, i + j));
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
