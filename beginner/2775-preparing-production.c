#include <stdio.h>

#define MAX_PACKETS 1000

void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int packets[MAX_PACKETS];
    int times[MAX_PACKETS];
    int swapped;
    int total;
    int i;
    int n;

    while(scanf("%d", &n) != EOF) {
        for (i = 0; i < n; i++) {
            scanf("%d", &packets[i]);
        }
        for (i = 0; i < n; i++) {
            scanf("%d", &times[i]);
        }
        total = 0;
        swapped = 1;
        while (swapped) {
            swapped = 0;
            for (i = 0; i < (n - 1); i++) {
                if (packets[i] > packets[i+1]) {
                    total += times[i] + times[i+1];
                    swap(&packets[i], &packets[i+1]);
                    swap(&times[i], &times[i+1]);
                    swapped = 1;
                }
            }
            n--;
        }
        printf("%d\n", total);
    }

    return 0;
}
