#include <stdio.h>

int main() {
    float i;
    float j;
    int count;
    int k;

    count = 0;
    i = 0;
    while (1) {
        for (k = 1; k <= 3; k++) {
            j = i + k;
            if ((count % 5) == 0) {
                printf("I=%d J=%d\n", (int) i, (int) j);
            } else {
                printf("I=%.1f J=%.1f\n", i, j);
            }
        }
        count += 1;
        i += 0.2;
        if (i > 2.1) {
            break;
        }
    }

    return 0;
}
