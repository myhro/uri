#include <stdio.h>

int main() {
    int total;
    int id;
    int g;
    int i;
    int n;
    int p;

    while(scanf("%d %d", &n, &id) != EOF) {
        total = 0;
        for (i = 0; i < n; i++) {
            scanf("%d %d", &p, &g);
            if ((p == id) && (g == 0)) {
                total++;
            }
        }
        printf("%d\n", total);
    }

    return 0;
}
