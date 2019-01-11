#include <stdio.h>

int ask() {
    int n;
    while (1) {
        printf("novo calculo (1-sim 2-nao)\n");
        scanf("%d", &n);
        if ((n < 1) || (n > 2)) {
            continue;
        }
        break;
    }
    return n;
}

int main() {
    float scores[2];
    float avg;
    float x;
    int i;

    i = 0;
    while(scanf("%f", &x) != EOF) {
        if ((x < 0) || (x > 10)) {
            printf("nota invalida\n");
            continue;
        }
        scores[i] = x;
        i++;
        if (i == 2) {
            avg = (scores[0] + scores[1]) / 2;
            i = 0;
            printf("media = %.2f\n", avg);
            if (ask() == 2) {
                break;
            }
        }
    }

    return 0;
}
