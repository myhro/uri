#include <stdio.h>
#include <string.h>

int eye(int rgb[]) {
    return rgb[0] * 0.3 + rgb[1] * 0.59 + rgb[2] * 0.11;
}

int max(int rgb[]) {
    int i;
    int r;

    r = -1;
    for (i = 0; i < 3; i++) {
        if (rgb[i] > r) {
            r = rgb[i];
        }
    }

    return r;
}

int mean(int rgb[]) {
    return (rgb[0] + rgb[1] + rgb[2]) / 3;
}

int min(int rgb[]) {
    int i;
    int r;

    r = 256;
    for (i = 0; i < 3; i++) {
        if (rgb[i] < r) {
            r = rgb[i];
        }
    }

    return r;
}

int main() {
    char op[8];
    int rgb[3];
    int i;
    int t;

    scanf("%d", &t);
    for (i = 1; i <= t; i++) {
        scanf("%s", op);
        scanf("%d %d %d", &rgb[0], &rgb[1], &rgb[2]);
        printf("Caso #%d: ", i);
        if (strcmp(op, "eye") == 0) {
            printf("%d", eye(rgb));
        } else if (strcmp(op, "max") == 0) {
            printf("%d", max(rgb));
        } else if (strcmp(op, "mean") == 0) {
            printf("%d", mean(rgb));
        } else if (strcmp(op, "min") == 0) {
            printf("%d", min(rgb));
        }
        printf("\n");
    }

    return 0;
}
