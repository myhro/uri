#include <stdio.h>

#define MAX_FARMS 1000001

int main() {
    unsigned long long sheeps;
    char attacked[MAX_FARMS];
    int farms[MAX_FARMS];
    int attacks;
    int next;
    int n;
    int i;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &farms[i]);
        attacked[i] = 0;
    }

    i = 0;
    while ((i >= 0) && (i < n)) {
        if ((farms[i] % 2) != 0) {
            next = i + 1;
        } else {
            next = i - 1;
        }
        if (farms[i] > 0) {
            attacked[i] = 1;
            farms[i]--;
        }
        i = next;
    }

    attacks = 0;
    sheeps = 0;
    for (i = 0; i < n; i++) {
        if (attacked[i] == 1) {
            attacks++;
        }
        sheeps += farms[i];
    }

    printf("%d %llu\n", attacks, sheeps);

    return 0;
}
