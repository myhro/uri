#include <string.h>
#include <stdio.h>

#define ALLSETS 10000
#define SETSIZE 61

int get_intersection(char *x, char *y) {
    int count = 0;
    int i;
    for (i = 1; i < SETSIZE; i++) {
        if (x[i] == 1 && y[i] == 1) {
            count++;
        }
    }
    return count;
}

int get_union(char *x, char *y) {
    int count = 0;
    int i;
    for (i = 1; i < SETSIZE; i++) {
        if (x[i] == 1 || y[i] == 1) {
            count++;
        }
    }
    return count;
}

int main() {
    char sets[ALLSETS][SETSIZE];
    int runs;
    int tmp;
    int op;
    int i;
    int j;
    int k;
    int m;
    int n;
    int q;
    int x;
    int y;

    scanf("%d", &runs);
    for (i = 0; i < runs; i++) {
        for (j = 0; j < ALLSETS; j++) {
            memset(sets[j], 0, SETSIZE);
        }
        scanf("%d", &n);
        for (j = 0; j < n; j++) {
            scanf("%d", &m);
            for (k = 0; k < m; k++) {
                scanf("%d", &tmp);
                sets[j+1][tmp] = 1;
            }
        }
        scanf("%d", &q);
        for (j = 0; j < q; j++) {
            scanf("%d %d %d", &op, &x, &y);
            if (op == 1) {
                tmp = get_intersection(sets[x], sets[y]);
                printf("%d\n", tmp);
            } else if (op == 2) {
                tmp = get_union(sets[x], sets[y]);
                printf("%d\n", tmp);
            }
        }
    }

    return 0;
}
