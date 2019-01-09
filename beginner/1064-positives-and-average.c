#include <stdio.h>

int main() {
    float list[6];
    float sum = 0;
    int i;
    int positives = 0;

    for (i = 0; i < 6; i++) {
        scanf("%f", &list[i]);
        if (list[i] > 0) {
            positives++;
            sum += list[i];
        }
    }

    printf("%d valores positivos\n", positives);
    printf("%.1f\n", sum / positives);

    return 0;
}
