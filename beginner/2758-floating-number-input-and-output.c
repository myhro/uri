#include <stdio.h>

int main() {
    float a;
    float b;
    double c;
    double d;

    scanf("%f %f", &a, &b);
    scanf("%lf %lf", &c, &d);

    printf("A = %f, B = %f\n", a, b);
    printf("C = %lf, D = %f\n", c, d);
    printf("A = %.1f, B = %.1f\n", a, b);
    printf("C = %.1lf, D = %.1f\n", c, d);
    printf("A = %.2f, B = %.2f\n", a, b);
    printf("C = %.2lf, D = %.2f\n", c, d);
    printf("A = %.3f, B = %.3f\n", a, b);
    printf("C = %.3lf, D = %.3f\n", c, d);
    printf("A = %.3E, B = %.3E\n", a, b);
    printf("C = %.3lE, D = %.3E\n", c, d);
    printf("A = %.0f, B = %.0f\n", a, b);
    printf("C = %.0lf, D = %.0f\n", c, d);

    return 0;
}
