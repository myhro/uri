#include <stdio.h>

#define SCORES 4

int main() {
    float scores[SCORES];
    float weights[SCORES] = {2, 3, 4, 1};
    float avg;
    float sum_scores;
    float sum_weights;
    float exam;
    int i;

    for (i = 0; i < SCORES; i++) {
        scanf("%f", &scores[i]);
    }

    sum_scores = 0;
    sum_weights = 0;
    for (i = 0; i < SCORES; i++) {
        sum_scores += scores[i] * weights[i];
        sum_weights += weights[i];
    }
    avg = sum_scores / sum_weights;

    printf("Media: %.1f\n", avg);

    if (avg < 5) {
        printf("Aluno reprovado.\n");
    } else if ((avg >= 5) && (avg < 7)) {
        printf("Aluno em exame.\n");
        scanf("%f", &exam);
        printf("Nota do exame: %.1f\n", exam);
        avg = (avg + exam) / 2;
        if (avg < 5) {
            printf("Aluno reprovado.\n");
        } else {
            printf("Aluno aprovado.\n");
        }
        printf("Media final: %.1f\n", avg);
    } else {
        printf("Aluno aprovado.\n");
    }

    return 0;
}
