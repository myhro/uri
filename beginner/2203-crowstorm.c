#include <math.h>
#include <stdio.h>

int main() {
    float di;
    float df;
    int r1;
    int r2;
    int v;
    int x1;
    int x2;
    int y1;
    int y2;

    while (scanf("%d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &v, &r1, &r2) != EOF) {
        di = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        df = di + 1.5 * v;
        if (df <= (r1 + r2)) {
            printf("Y\n");
        } else {
            printf("N\n");
        }
    }

    return 0;
}
