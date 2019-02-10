#include <stdio.h>

#define OFFSET 6

double time(float x) {
    return (60 * 60 * 24) / 360 * x;
}

int hour(float x) {
    return ((int) (time(x) / 3600) + OFFSET) % 24;
}

int min(float x) {
    return ((int) time(x) % 3600) / 60;
}

int sec(float x) {
    return (int) time(x) % 60;
}

int main() {
    float m;

    while (scanf("%f", &m) != EOF) {
        if ((m == 360) || (m < 90)) {
            printf("Bom Dia!!\n");
        } else if ((m >= 90) && (m < 180)) {
            printf("Boa Tarde!!\n");
        } else if ((m >= 180) && (m < 270)) {
            printf("Boa Noite!!\n");
        } else if (m >= 270) {
            printf("De Madrugada!!\n");
        }
        printf("%02d:%02d:%02d\n", hour(m), min(m), sec(m));
    }

    return 0;
}
