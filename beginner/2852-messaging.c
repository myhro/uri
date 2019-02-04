#include <stdio.h>
#include <string.h>

int isvowel(char c) {
    switch(c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return 1;
    }
    return 0;
}

int main() {
    char cipher[64];
    char input[100001];
    char *w;
    int crypt_len;
    int plain_len;
    int first;
    int i;
    int j;
    int k;
    int n;

    scanf("%s", cipher);
    scanf("%d", &n);
    crypt_len = strlen(cipher);
    while (n) {
        scanf(" %[^\n]s", input);
        first = 1;
        j = 0;
        w = strtok(input, " ");
        while (w != NULL) {
            if (!first) {
                printf(" ");
            }
            first = 0;
            if (!isvowel(w[0])) {
                plain_len = strlen(w);
                for (i = 0; i < plain_len; i++) {
                    k = ((w[i] - 'a') + (cipher[j] - 'a')) % 26;
                    printf("%c", 'a' + k);
                    j++;
                    if (j == crypt_len) {
                        j = 0;
                    }
                }
            } else {
                printf("%s", w);
            }
            w = strtok(NULL, " ");
        }
        printf("\n");
        n--;
    }

    return 0;
}
