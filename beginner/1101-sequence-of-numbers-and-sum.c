#include <stdio.h>

int min(int x, int y) {
    if (x < y) {
        return x;
    }
    return y;
}

int max(int x, int y) {
    if (x > y) {
        return x;
    }
    return y;
}

int main() {
    int last;
    int sum;
    int m;
    int n;
    int i;

    while (scanf("%d %d", &m, &n) != EOF) {
        if ((m <= 0) || (n == 0)) {
            break;
        }
        last = max(m, n);
        sum = 0;
        for (i = min(m, n); i <= last; i++) {
            printf("%d ", i);
            sum += i;
        }
        printf("Sum=%d\n", sum);
    }

    return 0;
}
