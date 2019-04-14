#include <stdio.h>

int main() {
    int boots[64][2];
    int pairs;
    char l;
    int d;
    int e;
    int i;
    int m;
    int n;

    while (scanf("%d", &n) != EOF) {
        for (i = 30; i <= 60; i++) {
            boots[i][0] = 0;
            boots[i][1] = 0;
        }
        for (i = 0; i < n; i++) {
            scanf("%d %c", &m, &l);
            boots[m][l - 'D']++;
        }
        pairs = 0;
        for (i = 30; i <= 60; i++) {
            d = boots[i][0];
            e = boots[i][1];
            if (d < e) {
                pairs += d;
            } else {
                pairs += e;
            }
        }
        printf("%d\n", pairs);
    }

    return 0;
}
