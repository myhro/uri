#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a;
    int b;
    int q;
    int r;

    scanf("%d %d", &a, &b);

    if ((a < 0) || (b > abs(a))) {
        q = 0;
        r = a;
    } else {
        q = a / b;
        r = a % b;
    }

    while (r < 0) {
        r += abs(b);
        q--;
    }

    if ((a < 0) && (b < 0)) {
        q *= -1;
    }

    printf("%d %d\n", q, r);

    return 0;
}
