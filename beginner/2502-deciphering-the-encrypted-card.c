#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define STR_SIZE 256

int main() {
    unsigned char cl;
    unsigned char cu;
    unsigned char pl;
    unsigned char pu;
    unsigned char *s;
    char cipher[STR_SIZE];
    char plain[STR_SIZE];
    char table[STR_SIZE];
    char line[65536];
    int c;
    int i;
    int n;

    while (scanf("%d %d", &c, &n) != EOF) {
        memset(table, 0, STR_SIZE);

        scanf(" %[^\n]s", plain);
        scanf(" %[^\n]s", cipher);

        for (i = 0; i < c; i++) {
            cu = toupper(cipher[i]);
            cl = tolower(cipher[i]);
            pu = toupper(plain[i]);
            pl = tolower(plain[i]);
            table[cu] = pu;
            table[cl] = pl;
            table[pu] = cu;
            table[pl] = cl;
        }

        for (i = 0; i < n; i++) {
            // Consume previous newline
            getchar();
            // Don't ignore leading whitespaces
            scanf("%[^\n]s", line);
            s = (unsigned char *) line;
            while (*s != '\0') {
                if (table[*s] != 0) {
                    printf("%c", table[*s]);
                } else {
                    printf("%c", *s);
                }
                s++;
            }
            printf("\n");
        }

        printf("\n");
    }

    return 0;
}
