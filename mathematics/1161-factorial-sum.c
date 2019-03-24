#include <stdio.h>

unsigned long long fact(int n) {
    unsigned long long total;

    if (n == 0) {
        return 1;
    }

    total = n;
    while (n > 1) {
        n--;
        total *= n;
    }

    return total;
}

int main() {
    int n;
    int m;

    while(scanf("%d %d", &n, &m) != EOF) {
        printf("%llu\n", fact(n) + fact(m));
    }

    return 0;
}
