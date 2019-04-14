#include <math.h>
#include <stdio.h>

int main() {
    double dist;
    int diff;
    int r1;
    int r2;
    int x1;
    int x2;
    int y1;
    int y2;

    while (scanf("%d %d %d %d %d %d", &r1, &x1, &y1, &r2, &x2, &y2) != EOF) {
        diff = r1 - r2;
        dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        if ((diff < 0) || (diff < dist)) {
            printf("MORTO\n");
        } else {
            printf("RICO\n");
        }
    }

    return 0;
}
