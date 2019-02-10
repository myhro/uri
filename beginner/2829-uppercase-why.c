#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    char *pa = *(char **) a;
    char *pb = *(char **) b;
    char *ca;
    char *cb;
    int s;

    s = strcasecmp(pa, pb);
    if (s == 0) {
        ca = pa;
        cb = pb;
        while((ca != '\0' || cb != '\0')) {
            if (isupper(*ca)) {
                return -1;
            }
            if (isupper(*cb)) {
                return 1;
            }
            ca++;
            cb++;
        }
    }

    return s;
}

int main() {
    int n;
    int i;
    char **wordlist;

    scanf("%d", &n);
    wordlist = (char **) malloc(n * sizeof(char *));
    for (i = 0; i < n; i++) {
        wordlist[i] = (char *) malloc(32 * sizeof(char));
        scanf("%s", wordlist[i]);
    }
    qsort(wordlist, n, sizeof(char **), compare);
    for (i = 0; i < n; i++) {
        printf("%s\n", wordlist[i]);
    }

    return 0;
}
