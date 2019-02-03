#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct shirt {
    char color[16];
    char name[256];
    char size[2];
};

int compare(const void *a, const void *b) {
    struct shirt *pa = (struct shirt *) a;
    struct shirt *pb = (struct shirt *) b;
    int cmp;

    cmp = strcmp(pa->color, pb->color);
    if (cmp != 0) {
        return cmp;
    }

    cmp = strcmp(pb->size, pa->size);
    if (cmp != 0) {
        return cmp;
    }

    return strcmp(pa->name, pb->name);
}

int main() {
    struct shirt students[64];
    int first;
    int n;
    int i;

    first = 1;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        for (i = 0; i < n; i++) {
            scanf(" %[^\n]s", students[i].name);
            scanf("%s %s", students[i].color, students[i].size);
        }
        qsort(students, n, sizeof(struct shirt), compare);
        if (!first) {
            printf("\n");
        }
        first = 0;
        for (i = 0; i < n; i++) {
            printf("%s %s %s\n", students[i].color, students[i].size, students[i].name);
        }
    }

    return 0;
}
