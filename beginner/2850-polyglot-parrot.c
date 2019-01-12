#include <stdio.h>
#include <string.h>

int main() {
    char input[256];

    while (scanf(" %[^\n]s", input) != EOF) {
        if (strcmp(input, "esquerda") == 0) {
            printf("ingles\n");
        } else if (strcmp(input, "direita") == 0) {
            printf("frances\n");
        } else if (strcmp(input, "nenhuma") == 0) {
            printf("portugues\n");
        } else {
            printf("caiu\n");
        }
    }

    return 0;
}
