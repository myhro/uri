#include <stdio.h>

unsigned long long fib(int n) {
    unsigned long long tmp;
    unsigned long long p;
    unsigned long long r;

    if ((n == 0) || (n == 1)) {
        return n;
    }

    p = 0;
    r = 1;
    while (n > 1) {
        tmp = p + r;
        p = r;
        r = tmp;
        n--;
    }

    return r;
}

int main() {
    int i;
    int n;
    int t;

    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("Fib(%d) = %llu\n", n, fib(n));
    }

    return 0;
}
