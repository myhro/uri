#include <stdio.h>

int main() {
    char n[128];
    char *c;
    char d;
    int empty;

    while (scanf(" %c %s", &d, n) != EOF) {
        if (d == '0') {
            break;
        }
        empty = 1;
        for (c = n; *c != '\0'; c++) {
            if (empty && (*c == '0')) {
                continue;
            } else if (*c != d) {
                printf("%c", *c);
                empty = 0;
            }
        }
        if (empty) {
            printf("0");
        }
        printf("\n");
    }

    return 0;
}
