#include <stdio.h>
#include <string.h>

void check(char history[][101], int n, char *q) {
    int hits;
    int len;
    int max;
    int i;

    hits = 0;
    max = -1;
    for (i = 0; i < n; i++) {
        if (strstr(history[i], q) != NULL) {
            len = strlen(history[i]);
            if (len > max) {
                max = len;
            }
            hits++;
        }
    }

    if (hits == 0) {
        printf("-1\n");
    } else {
        printf("%d %d\n", hits, max);
    }
}

int main() {
    char history[1000][101];
    char query[101];
    int i;
    int n;
    int q;

    while(scanf("%d", &n) != EOF) {
        for (i = 0; i < n; i++) {
            scanf("%s", history[i]);
        }
        scanf("%d", &q);
        for (i = 0; i < q; i++) {
            scanf("%s", query);
            check(history, n, query);
        }
    }

    return 0;
}
