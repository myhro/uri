#include <stdio.h>
#include <stdlib.h>

#define LIST_SIZE 305001

int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int position(int *first, int *found) {
    if (found == NULL) {
        return -1;
    }
    return (found - first);
}

int main() {
    int list[LIST_SIZE] = {0};
    int *result;
    int pos;
    int i;
    int m;
    int n;
    int lucky;

    while (scanf("%d", &n) != EOF) {
        for (i = 0; i < n; i++) {
            scanf("%d", &list[i+1]);
        }
        scanf("%d", &m);

        i = 2;
        lucky = 1;
        result = bsearch(&m, list, n+1, sizeof(int), compare);
        pos = position(list, result);

        while (pos >= i) {
            if (pos % i == 0) {
                lucky = 0;
                break;
            }
            pos -= pos / i;
            i++;
        }

        if (lucky == 0) {
            printf("N\n");
        } else {
            printf("Y\n");
        }
    }

    return 0;
}
