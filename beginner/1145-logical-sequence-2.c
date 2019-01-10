#include <stdio.h>

int main() {
    int i;
    int x;
    int y;

    scanf("%d %d", &x, &y);

    for (i = 1; i < y; i++) {
        printf("%d", i);
        if ((i % x) == 0) {
            printf("\n");
        } else {
            printf(" ");
        }
    }
    printf("%d\n", y);

    return 0;
}
