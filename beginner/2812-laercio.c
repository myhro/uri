#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int list[1000];
    int tmp;
    int i;
    int j;
    int k;
    int l;
    int m;
    int n;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &m);
        l = 0;
        for (j = 0; j < m; j++) {
            scanf("%d", &tmp);
            if ((tmp % 2) != 0) {
                list[l] = tmp;
                l++;
            }
        }
        if (l == 0) {
            printf("\n");
            continue;
        }

        qsort(list, l, sizeof(int), compare);
        j = 0;
        k = l - 1;
        while (j < k) {
            printf("%d ", list[k]);
            printf("%d", list[j]);
            if (j != (k - 1)) {
                printf(" ");
            }
            j++;
            k--;
        }
        if ((l % 2) != 0) {
            printf("%d", list[j]);
        }
        printf("\n");
    }

    return 0;
}
