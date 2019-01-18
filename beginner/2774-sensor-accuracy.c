#include <math.h>
#include <stdio.h>

double mean(double *a, int n) {
    double sum;
    int i;

    sum = 0;
    for (i = 0; i < n; i++) {
        sum += a[i];
    }

    return sum / n;
}

int main() {
    double measures[100001];
    double acc;
    double sum;
    double y;
    int count;
    int h;
    int m;
    int n;
    int i;

    while (scanf("%d %d", &h, &m) != EOF) {
        n = h * 60;
        count = 0;
        for (i = m; i <= n; i += m) {
            scanf("%lf", &measures[count]);
            count++;
        }
        sum = 0;
        y = mean(measures, count);
        for (i = 0; i < count; i++) {
            sum += pow(measures[i] - y, 2);
        }
        acc = sqrt(sum / (count - 1));
        printf("%.5lf\n", acc);
    }

    return 0;
}
