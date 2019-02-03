#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return strlen((char *) b) - strlen((char *) a);
}

int main() {
    char wordlist[256][256];
    char input[16384];
    char *w;
    int total;
    int i;
    int j;
    int n;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf(" %[^\n]s", input);
        j = 0;
        w = strtok(input, " ");
        while (w != NULL) {
            strcpy(wordlist[j], w);
            j++;
            w = strtok(NULL, " ");
        }
        total = j;
        qsort(wordlist, total, sizeof(wordlist[0]), compare);
        for (j = 0; j < total; j++) {
            printf("%s", wordlist[j]);
            if (j != (total -1)) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
