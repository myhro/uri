#include <stdio.h>
#include <string.h>

#define CENTER_MARGIN_1 3
#define CENTER_MARGIN_2 4
#define HEADER_MARGIN 2
#define LEFT_MARGIN_1 5
#define LEFT_MARGIN_2 4
#define LINE_WIDTH 39
#define RIGHT_MARGIN 7

void columns(int n) {
    int i;
    int j;

    for (i = 0; i < n; i++) {
        printf("|");
        for (j = 0; j < LEFT_MARGIN_1; j++) {
            printf(" ");
        }
        printf("%2d", i);
        for (j = 0; j < LEFT_MARGIN_2; j++) {
            printf(" ");
        }
        printf("|");
        for (j = 0; j < CENTER_MARGIN_1; j++) {
            printf(" ");
        }
        printf("%2o", i);
        for (j = 0; j < CENTER_MARGIN_2; j++) {
            printf(" ");
        }
        printf("|");
        for (j = 0; j < RIGHT_MARGIN; j++) {
            printf(" ");
        }
        printf("%X", i);
        for (j = 0; j < RIGHT_MARGIN; j++) {
            printf(" ");
        }
        printf("|\n");
    }
}

void header() {
    char titles[][16] = {"decimal", "octal", "Hexadecimal"};
    int i;
    int j;

    printf("|");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < HEADER_MARGIN; j++) {
            printf(" ");
        }
        printf("%s", titles[i]);
        for (j = 0; j < HEADER_MARGIN; j++) {
            printf(" ");
        }
        printf("|");
    }
    printf("\n");
}

void line() {
    int i;
    for (i = 0; i < LINE_WIDTH; i++) {
        printf("-");
    }
    printf("\n");
}

int main() {
    line();
    header();
    line();
    columns(16);
    line();
    return 0;
}
