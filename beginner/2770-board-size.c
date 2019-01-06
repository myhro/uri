#include <stdio.h>

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int main() {
    int dx;
    int dy;
    int i;
    int m;
    int x;
    int y;

    while (scanf("%d %d %d", &x, &y, &m) != EOF) {
        for (i = 0; i < m; i++) {
            scanf("%d %d", &dx, &dy);
            if ((dx > x) && (dx > y)) {
                printf("Nao\n");
            } else if ((dy > x) && (dy > y)) {
                printf("Nao\n");
            } else if ((dx > min(x, y)) && (dy > min(x, y))) {
                printf("Nao\n");
            } else {
                printf("Sim\n");
            }
        }
    }

    return 0;
}
