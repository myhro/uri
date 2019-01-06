#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
    char s[65536];
    int c;
    int i;
    int n;

    scanf("%d", &c);
    for (i = 0; i < c; i++) {
        scanf("%s", s);
        n = strlen(s);
        while (n > 0) {
            n--;
            if (islower(s[n])) {
                printf("%c", s[n]);
            }
        }
        printf("\n");
    }

    return 0;
}
