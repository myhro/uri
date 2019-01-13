#include <stdio.h>

int main() {
    int list[40];
    int n;
    int i;

    scanf("%d", &n);

    list[0] = 1;
    list[1] = 1;

    for (i = 2; i < n; i++) {
        list[i] = list[i-1] + list[i-2];
    }

    for (i = (n - 1); i >= 0; i--) {
        printf("%d", list[i]);
        if (i != 0) {
            printf(" ");
        }
    }

    printf("\n");

    return 0;
}
