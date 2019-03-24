#include <ctype.h>
#include <stdio.h>

int main() {
    char s[64];
    char *c;
    int upper;

    while(scanf("%[^\n]", s) != EOF) {
        c = s;
        upper = 1;
        while (*c != '\0') {
            if (islower(*c) || isupper(*c)) {
                if (upper) {
                    printf("%c", toupper(*c));
                    upper = 0;
                } else {
                    printf("%c", tolower(*c));
                    upper = 1;
                }
            } else {
                printf("%c", *c);
            }
            c++;
        }
        printf("\n");
        // discard newline, as leading spaces can't be discarded on scanf:
        getchar();
    }

    return 0;
}
