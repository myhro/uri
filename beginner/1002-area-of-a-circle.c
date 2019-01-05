#include <math.h>
#include <stdio.h>

int main() {
    double n = 3.14159;
    double a;
    double r;
    scanf("%lf", &r);
    a = n * pow(r, 2);
    printf("A=%.4lf\n", a);
    return 0;
}
