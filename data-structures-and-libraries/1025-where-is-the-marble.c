#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int marbles[10001];
    int cases;
    int found;
    int query;
    int i;
    int j;
    int n;
    int q;

    cases = 0;
    while (scanf("%d %d", &n, &q) != EOF) {
        if ((n == 0) && (q == 0)) {
            break;
        }
        for (i = 0; i < n; i++) {
            scanf("%d", &marbles[i]);
        }
        qsort(marbles, n, sizeof(int), compare);
        cases++;
        printf("CASE# %d:\n", cases);
        for (i = 0; i < q; i++) {
            scanf("%d", &query);
            found = 0;
            for (j = 0; j < n; j++) {
                if (marbles[j] == query) {
                    found = 1;
                    printf("%d found at %d\n", query, j + 1);
                    break;
                }
            }
            if (!found) {
                printf("%d not found\n", query);
            }
        }
    }
    return 0;
}
