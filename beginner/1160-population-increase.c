#include <stdio.h>

int main() {
    float g1;
    float g2;
    int years;
    int pa;
    int pb;
    int t;

    scanf("%d", &t);
    while (t) {
        scanf("%d %d %f %f", &pa, &pb, &g1, &g2);
        g1 = 1 + g1 / 100;
        g2 = 1 + g2 / 100;
        years = 1;
        while (1) {
            pa *= g1;
            pb *= g2;
            if (pa > pb) {
                printf("%d anos.\n", years);
                break;
            }
            years++;
            if (years > 100) {
                printf("Mais de 1 seculo.\n");
                break;
            }
        }
        t--;
    }

    return 0;
}
