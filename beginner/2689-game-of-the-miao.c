#include <stdio.h>
#include <stdlib.h>

int main() {
    int cases[3][3];
    int diff[3][3];
    int freq[101];
    int biggest;
    int first;
    int most;
    int i;
    int j;
    int k;
    int l;
    int p;

    scanf("%d", &p);
    while (p) {
        for (i = 0; i < 101; i++) {
            freq[i] = 0;
        }
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                scanf("%d", &cases[i][j]);
            }
            diff[i][0] = abs(cases[i][0] - cases[i][1]);
            diff[i][1] = abs(cases[i][1] - cases[i][0]);
            diff[i][2] = abs(cases[i][2] - cases[i][1]);
        }
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                freq[diff[i][j]]++;
            }
        }
        biggest = 0;
        most = 0;
        for (i = 0; i < 101; i++) {
            if (freq[i] > biggest) {
                biggest = freq[i];
                most = i;
            }
        }
        printf("Possiveis maletas: ");
        first = 1;
        k = 1;
        l = 2;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if ((abs(cases[i][j] - cases[i][k]) != most) &&
                    (abs(cases[i][j] - cases[i][l]) != most)) {
                    if (!first) {
                        printf(", ");
                    }
                    first = 0;
                    printf("%d", cases[i][j]);
                }
                k = (k + 1) % 3;
                l = (l + 1) % 3;
            }
        }
        printf(";\n");
        p--;
    }

    return 0;
}
