#include <stdio.h>
#include <string.h>

int main() {
    char words[64][64];
    int lenghts[64];
    int longest;
    int first;
    int i;
    int j;
    int n;

    first = 1;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        longest = 0;
        for (i = 0; i < n; i++) {
            scanf("%s", words[i]);
            lenghts[i] = strlen(words[i]);
            if (lenghts[i] > longest) {
                longest = lenghts[i];
            }
        }
        if (!first) {
            printf("\n");
        }
        first = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < (longest - lenghts[i]); j++) {
                printf(" ");
            }
            printf("%s\n", words[i]);
        }
    }

    return 0;
}
