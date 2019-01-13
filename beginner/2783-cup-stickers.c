#include <stdio.h>
#include <stdlib.h>

#define MAX_STICKERS 1000

int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int bought[MAX_STICKERS] = {0};
    int stamps[MAX_STICKERS];
    int remain;
    int tmp;
    int *r;
    int c;
    int i;
    int m;
    int n;

    scanf("%d %d %d", &n, &c, &m);

    for (i = 0; i < c; i++) {
        scanf("%d", &stamps[i]);
    }
    qsort(stamps, c, sizeof(int), compare);

    for (i = 0; i < m; i++) {
        scanf("%d", &tmp);
        bought[tmp] = 1;
    }

    remain = c;
    for (i = 1; i <= n; i++) {
        if (bought[i] != 0) {
            r = bsearch(&i, stamps, c, sizeof(int), compare);
            if (r != NULL) {
                remain--;
            }
        }
    }

    printf("%d\n", remain);

    return 0;
}
