#include <stdio.h>

int main() {
    char input[16];
    int tmp;

    while (scanf("%s", input) != EOF) {
        if (input[0] == '-') {
            break;
        }
        if ((input[0] == '0') && (input[1] == 'x')) {
            sscanf(input, "%x", &tmp);
            printf("%d\n", tmp);
        } else {
            sscanf(input, "%d", &tmp);
            printf("0x%X\n", tmp);
        }
    }

    return 0;
}
