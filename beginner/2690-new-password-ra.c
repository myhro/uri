#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(char *) a - *(char *) b;
}

int convert(char c) {
    char zero[] = {'G', 'Q', 'a', 'k', 'u'};
    char one[] = {'I', 'S', 'b', 'l', 'v'};
    char two[] = {'E', 'O', 'Y', 'c', 'm', 'w'};
    char three[] = {'F', 'P', 'Z', 'd', 'n', 'x'};
    char four[] = {'J', 'T', 'e', 'o', 'y'};
    char five[] = {'D', 'N', 'X', 'f', 'p', 'z'};
    char six[] = {'A', 'K', 'U', 'g', 'q'};
    char seven[] = {'C', 'M', 'W', 'h', 'r'};
    char eight[] = {'B', 'L', 'V', 'i', 's'};
    char nine[] = {'H', 'R', 'j', 't'};
    char *numbers[] = {zero, one, two, three, four, five, six, seven, eight, nine};
    char *r;
    int lenghts[] = {sizeof(zero), sizeof(one), sizeof(two), sizeof(three),
        sizeof(four), sizeof(five), sizeof(six), sizeof(seven), sizeof(eight),
        sizeof(nine)};
    int i;

    for (i = 0; i < 10; i++) {
        r = bsearch(&c, numbers[i], lenghts[i], sizeof(char), compare);
        if (r != NULL) {
            return i;
        }
    }

    return -1;
}

int main() {
    char input[65536];
    char *c;
    int printed;
    int i;
    int n;
    int r;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf(" %[^\n]s", input);
        c = input;
        printed = 0;
        while (*c != '\0') {
            r = convert(*c);
            if (r >= 0) {
                printf("%d", r);
                printed++;
            }
            if (printed == 12) {
                break;
            }
            c++;
        }
        printf("\n");
    }

    return 0;
}
