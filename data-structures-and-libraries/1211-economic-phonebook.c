#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    char *pa = *(char **) a;
    char *pb = *(char **) b;
    return strcmp(pa, pb);
}

int main() {
    char **phones;
    int length;
    int saved;
    int i;
    int j;
    int n;
    int p;

    phones = (char **) malloc(100000 * sizeof(char *));
    while (scanf("%d", &n) != EOF) {
        for (i = 0; i < n; i++) {
            phones[i] = (char *) malloc(201 * sizeof(char));
            scanf("%s", phones[i]);
        }
        length = strlen(phones[0]);
        qsort(phones, n, sizeof(char **), compare);
        saved = 0;
        for (i = 1; i < n; i++) {
            p = i - 1;
            for (j = 0; j < length; j++) {
                if (phones[p][j] == phones[i][j]) {
                    saved++;
                } else {
                    break;
                }
            }
        }
        printf("%d\n", saved);
        for (i = 0; i < n; i++) {
            free(phones[i]);
        }
    }

    return 0;
}
