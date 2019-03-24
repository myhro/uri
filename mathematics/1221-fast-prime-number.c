#include <stdio.h>

int prime(unsigned int n) {
    unsigned int i;

    if (n <= 3) {
        return n > 1;
    } else if ((n % 2 == 0) || (n % 3 == 0)) {
        return 0;
    }

    for (i = 5; (i * i) <= n; i += 6) {
        if ((n % i == 0) || (n % (i + 2) == 0)) {
            return 0;
        }
    }

    return 1;
}

int main() {
    unsigned int n, x;

    scanf("%u", &n);
    while (n > 0) {
        scanf("%u", &x);
        if (prime(x)) {
            printf("Prime\n");
        } else {
            printf("Not Prime\n");
        }
        n--;
    }

    return 0;
}
