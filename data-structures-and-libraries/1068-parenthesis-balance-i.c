#include <stdio.h>

int main() {
    char input[1024];
    int i;
    char *c;

    while (scanf("%s", input) != EOF) {
        i = 0;
        c = input;
        while (*c != '\0') {
            if (*c == '(') {
                i++;
            } else if (*c == ')') {
                i--;
            }
            if (i < 0) {
                break;
            }
            c++;
        }
        if (i == 0) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}
