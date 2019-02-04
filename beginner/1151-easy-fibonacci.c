#include <stdio.h>

int main() {
    int first;
    int prev;
    int cur;
    int tmp;
    int n;

    scanf("%d", &n);
    prev = 0;
    cur = 1;
    first = 1;
    while (n) {
        if (!first) {
            printf(" ");
        }
        first = 0;
        printf("%d", prev);
        tmp = cur;
        cur += prev;
        prev = tmp;
        n--;
    }
    printf("\n");

    return 0;
}
