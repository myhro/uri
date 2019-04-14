#include <stdio.h>

int main() {
    int grades[1001];
    float perc;
    int above;
    int avg;
    int sum;
    int c;
    int i;
    int n;

    scanf("%d", &c);
    while (c > 0) {
        scanf("%d", &n);
        sum = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &grades[i]);
            sum += grades[i];
        }
        above = 0;
        avg = sum / n;
        for (i = 0; i < n; i++) {
            if (grades[i] > avg) {
                above++;
            }
        }
        perc = above / (float) n * 100;
        printf("%.3f%%\n", perc);
        c--;
    }

    return 0;
}
