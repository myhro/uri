#include <stdio.h>
#include <string.h>

char translate(char *str) {
    if (strcmp(str, "=.===") == 0) { // A .-
        return 'a';
    } else if (strcmp(str, "===.=.=.=") == 0) { // B -...
        return 'b';
    } else if (strcmp(str, "===.=.===.=") == 0) { // C -.-.
        return 'c';
    } else if (strcmp(str, "===.=.=") == 0) { // D -..
        return 'd';
    } else if (strcmp(str, "=") == 0) { // E .
        return 'e';
    } else if (strcmp(str, "=.=.===.=") == 0) { // F ..-.
        return 'f';
    } else if (strcmp(str, "===.===.=") == 0) { // G --.
        return 'g';
    } else if (strcmp(str, "=.=.=.=") == 0) { // H ....
        return 'h';
    } else if (strcmp(str, "=.=") == 0) { // I ..
        return 'i';
    } else if (strcmp(str, "=.===.===.===") == 0) { // J .---
        return 'j';
    } else if (strcmp(str, "===.=.===") == 0) { // K -.-
        return 'k';
    } else if (strcmp(str, "=.===.=.=") == 0) { // L .-..
        return 'l';
    } else if (strcmp(str, "===.===") == 0) { // M --
        return 'm';
    } else if (strcmp(str, "===.=") == 0) { // N -.
        return 'n';
    } else if (strcmp(str, "===.===.===") == 0) { // O ---
        return 'o';
    } else if (strcmp(str, "=.===.===.=") == 0) { // P .--.
        return 'p';
    } else if (strcmp(str, "===.===.=.===") == 0) { // Q --.-
        return 'q';
    } else if (strcmp(str, "=.===.=") == 0) { // R .-.
        return 'r';
    } else if (strcmp(str, "=.=.=") == 0) { // S ...
        return 's';
    } else if (strcmp(str, "===") == 0) { // T -
        return 't';
    } else if (strcmp(str, "=.=.===") == 0) { // U ..-
        return 'u';
    } else if (strcmp(str, "=.=.=.===") == 0) { // V ...-
        return 'v';
    } else if (strcmp(str, "=.===.===") == 0) { // W .--
        return 'w';
    } else if (strcmp(str, "===.=.=.===") == 0) { // X -..-
        return 'x';
    } else if (strcmp(str, "===.=.===.===") == 0) { // Y -.--
        return 'y';
    } else if (strcmp(str, "===.===.=.=") == 0) { // Z --..
        return 'z';
    }
    return ' ';
}

void print_morse(char *code) {
    printf("%c", translate(code));
}

char* next_morse(char *code) {
    char point[] = "...";
    char space[] = ".......";
    char sub[16];
    char *match;
    int n;

    match = strstr(code, point);

    if (match == NULL) {
        print_morse(code);
        return NULL;
    }

    n = match - code;
    strncpy(sub, code, n);
    sub[n] = '\0';
    print_morse(sub);

    n = strlen(space);
    strncpy(sub, match, n);
    sub[n] = '\0';
    if (strcmp(sub, space) == 0) {
        printf(" ");
        return match + strlen(space);
    }

    return match + strlen(point);
}

int main() {
    char code[1001];
    char *current;
    int t;
    int i;
    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        scanf("%s", code);
        current = code;
        while(current != NULL) {
            current = next_morse(current);
        }
        printf("\n");
    }
    return 0;
}
