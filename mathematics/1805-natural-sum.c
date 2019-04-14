#include <stdio.h>

int main() {
    unsigned long long a;
    unsigned long long b;
    unsigned long long sum;

    scanf("%llu %llu", &a, &b);
    sum = b * (b + 1) / 2;
    if (a > 1) {
        sum -= a * (a + 1) / 2 - a;
    }

    printf("%llu\n", sum);

    return 0;
}
