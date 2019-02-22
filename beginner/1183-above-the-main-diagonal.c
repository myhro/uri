#include <stdio.h>

int main() {
    char o;
    float total;
    float tmp;
    int count;
    int i;
    int j;

    scanf("%c", &o);
    count = 0;
    total = 0;
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 12; j++) {
            scanf("%f", &tmp);
            if (j > i) {
                count++;
                total += tmp;
            }
        }
    }
    if (o == 'S') {
        printf("%.1f\n", total);
    } else {
        printf("%.1f\n", total / count);
    }

    return 0;
}
