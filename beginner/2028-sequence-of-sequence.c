#include <stdio.h>

int main() {
    int sequence[32768];
    int i;
    int j;
    int k;
    int m;
    int n;

    m = 0;
    while (scanf("%d", &n) != EOF) {
        sequence[0] = 0;
        k = 1;
        if (n > 0) {
            for (i = 1; i < (n + 1); i++) {
                for (j = 0; j < i; j++) {
                    sequence[k] = i;
                    k++;
                }
            }
        }
        m++;
        printf("Caso %d: %d ", m, k);
        if (k == 1) {
            printf("numero\n");
        } else {
            printf("numeros\n");
        }
        for (i = 0; i < (k - 1); i++) {
            printf("%d ", sequence[i]);
        }
        printf("%d", sequence[k-1]);
        printf("\n\n");
    }

    return 0;
}
