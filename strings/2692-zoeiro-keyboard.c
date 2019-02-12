#include <stdio.h>

int main() {
    char keyboard[256] = {0};
    unsigned char input[256];
    unsigned char *c;
    unsigned char e;
    unsigned char s;
    int m;
    int n;

    scanf("%d %d", &n, &m);
    while (n) {
        scanf(" %c %c", &e, &s);
        keyboard[e] = s;
        keyboard[s] = e;
        n--;
    }
    while (m) {
        scanf(" %[^\n]s", input);
        c = input;
        while (*c != '\0') {
            if (keyboard[*c] != 0) {
                printf("%c", keyboard[*c]);
            } else {
                printf("%c", *c);
            }
            c++;
        }
        printf("\n");
        m--;
    }

    return 0;
}
