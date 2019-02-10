#include <stdio.h>

int main() {
    long double sum;
    int c;
    int n;
    int p;

    scanf("%d", &n);
    sum = 0;
    while (n) {
        scanf("%d %d", &c, &p);
        sum += (long double) c / (long double) p;
        n--;
    }
    if (sum <= 1) {
        printf("OK\n");
    } else {
        printf("FAIL\n");
    }

    return 0;
}
