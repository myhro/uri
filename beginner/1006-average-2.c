#include <stdio.h>

int main() {
    float w_a = 2;
    float w_b = 3;
    float w_c = 5;
    float a;
    float b;
    float c;
    float media;

    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);

    media = (a * w_a + b * w_b + c * w_c) / (w_a + w_b + w_c) ;

    printf("MEDIA = %.1f\n", media);

    return 0;
}
