#include <stdio.h>

int main() {
    unsigned long long g;
    int max;
    int seq;
    int i;
    int n;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%llu", &g);

        max = 0;
        seq = 0;
        while (g > 0) {
            if ((g & 1) == 1) {
                seq++;
                if (seq > max) {
                    max = seq;
                }
            } else {
                seq = 0;
            }
            g >>= 1;
        }

        printf("%d\n", max);
    }

    return 0;
}
