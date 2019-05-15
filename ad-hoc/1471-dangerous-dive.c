#include <stdio.h>

int main() {
    int divers[10001];
    int tmp;
    int i;
    int n;
    int r;

    while(scanf("%d %d", &n, &r) != EOF) {
        for (i = 0; i <= n; i++) {
            divers[i] = 0;
        }
        for (i = 0; i < r; i++) {
            scanf("%d", &tmp);
            divers[tmp] = 1;
        }
        if (n == r) {
            printf("*\n");
            continue;
        }
        for (i = 1; i <= n; i++) {
            if (divers[i] == 0) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }

    return 0;
}
