#include <stdio.h>

int main() {
    double a;
    double b;
    double media;
    double w_a = 3.5;
    double w_b = 7.5;

    scanf("%lf", &a);
    scanf("%lf", &b);

    media = (a * w_a + b * w_b) / (w_a + w_b) ;

    printf("MEDIA = %.5lf\n", media);

    return 0;
}
