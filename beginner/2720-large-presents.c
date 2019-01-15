#include <stdio.h>
#include <stdlib.h>

struct gift {
    int id;
    int vol;
};

int compare_id(const void *a, const void *b) {
    struct gift *pa = (struct gift *) a;
    struct gift *pb = (struct gift *) b;
    return pa->id - pb->id;
}

int compare_vol(const void *a, const void *b) {
    struct gift *pa = (struct gift *) a;
    struct gift *pb = (struct gift *) b;
    if (pa->vol == pb->vol) {
        return pa->id - pb->id;
    }
    return pb->vol - pa->vol;
}

int main() {
    struct gift santa[100001];
    int id;
    int h;
    int i;
    int j;
    int k;
    int l;
    int n;
    int t;
    int w;

    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        scanf("%d %d", &n, &k);
        for (j = 0; j < n; j++) {
            scanf("%d %d %d %d", &id, &h, &w, &l);
            santa[j].id = id;
            santa[j].vol = h * w * l;
        }
        qsort(santa, n, sizeof(struct gift), compare_vol);
        qsort(santa, k, sizeof(struct gift), compare_id);
        for (j = 0; j < k; j++) {
            printf("%d", santa[j].id);
            if (j != (k - 1)) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
