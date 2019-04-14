#include <stdio.h>

int count_out(int n, int k) {
    if (n == 1) {
        return 0;
    }
    return (count_out(n - 1, k) + k) % n;
}

int main() {
    int nc;
    int i;
    int k;
    int n;

    scanf("%d", &nc);
    for (i = 0; i < nc; i++) {
        scanf("%d %d", &n, &k);
        printf("Case %d: %d\n", i + 1, count_out(n, k) + 1);
    }

    return 0;
}
