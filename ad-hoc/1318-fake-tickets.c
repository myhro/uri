#include <stdio.h>

#define NUM_TICKETS 10001

int main() {
    int tickets[NUM_TICKETS];
    int clones;
    int i;
    int m;
    int n;
    int p;

    while (scanf("%d %d", &n, &m) != EOF) {
        if (n == 0) {
            break;
        }
        for (i = 0; i < NUM_TICKETS; i++) {
            tickets[i] = 0;
        }
        for (i = 0; i < m; i++) {
            scanf("%d", &p);
            tickets[p-1]++;
        }
        clones = 0;
        for (i = 0; i < n; i++) {
            if (tickets[i] > 1) {
                clones++;
            }
        }
        printf("%d\n", clones);
    }

    return 0;
}
