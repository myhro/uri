#include <math.h>
#include <stdio.h>

int main() {
    float delta;
    float r1;
    float r2;
    float a;
    float b;
    float c;

    scanf("%f %f %f", &a, &b, &c);

    delta = pow(b, 2) - 4 * a * c;

    if (a == 0 || delta < 0) {
        printf("Impossivel calcular\n");
    } else {
        r1 = ((b * -1) + sqrt(delta)) / (2 * a);
        r2 = ((b * -1) - sqrt(delta)) / (2 * a);
        printf("R1 = %.5f\n", r1);
        printf("R2 = %.5f\n", r2);
    }

    return 0;
}
