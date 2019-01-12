#include <stdio.h>
#include <stdlib.h>

int main() {
    int d;
    int i;
    int j;
    int m;
    int n;
    int p;
    int x1;
    int x2;
    int y1;
    int y2;

    while (scanf("%d %d", &n, &m) != EOF) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                scanf("%d", &p);
                if (p == 2) {
                    x2 = i;
                    y2 = j;
                } else if (p == 1) {
                    x1 = i;
                    y1 = j;
                }
            }
        }
        d = abs(x2 - x1) + abs(y2 - y1);
        printf("%d\n", d);
    }

    return 0;
}
