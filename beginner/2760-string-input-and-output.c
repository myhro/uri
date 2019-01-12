#include <stdio.h>

int main() {
    char input[3][65536];
    int i;

    for (i = 0; i < 3; i++) {
        scanf(" %[^\n]s", input[i]);
    }

    printf("%s%s%s\n", input[0], input[1], input[2]);
    printf("%s%s%s\n", input[1], input[2], input[0]);
    printf("%s%s%s\n", input[2], input[0], input[1]);
    printf("%.10s%.10s%.10s\n", input[0], input[1], input[2]);

    return 0;
}
