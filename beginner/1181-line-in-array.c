#include <stdio.h>

float sum(float *array) {
    int i;
    float r = 0;
    for (i = 0; i < 12; i++) {
        r += array[i];
    }
    return r;
}

int main() {
    float matrix[12][12];
    float result;
    char op;
    int line;
    int i;
    int j;

    scanf("%d", &line);
    scanf(" %c", &op);
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 12; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    if (op == 'S') {
        result = sum(matrix[line]);
    } else {
        result = sum(matrix[line]) / 12;
    }

    printf("%.1f\n", result);

    return 0;
}
