#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *) b - *(int *) a;
}

int main() {
    int grades[101];
    int i;
    int j;
    int n;
    int q;

    while (scanf("%d %d", &n, &q) != EOF) {
        for (i = 0; i < n; i++) {
            scanf("%d", &grades[i]);
        }
        qsort(grades, n, sizeof(int), compare);
        for (i = 0; i < q; i++) {
            scanf("%d", &j);
            printf("%d\n", grades[j-1]);
        }
    }

    return 0;
}
