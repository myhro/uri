#include <stdio.h>
#include <string.h>

#define CENTER 1
#define HALF_WIDTH 17
#define LEFT 0
#define LINE_WIDTH 39
#define MARGIN 2
#define RIGHT 2

void print(char *str, int pos) {
    int i;
    int l;
    int n;
    int r;

    l = 0;
    r = 0;
    n = strlen(str);
    if (pos == LEFT) {
        r = LINE_WIDTH - MARGIN - n;
    } else if (pos == RIGHT) {
        l = LINE_WIDTH - MARGIN - n;
    } else if (pos == CENTER) {
        l = HALF_WIDTH - MARGIN;
        r = LINE_WIDTH - HALF_WIDTH - n;
    }

    printf("|");

    for (i = 0; i < l; i++) {
        printf(" ");
    }
    printf("%s", str);
    for (i = 0; i < r; i++) {
        printf(" ");
    }

    printf("|\n");
}

void blank() {
    print("", CENTER);
}

void center(char *str) {
    print(str, CENTER);
}

void left(char *str) {
    print(str, LEFT);
}

void right(char *str) {
    print(str, RIGHT);
}

void line() {
    int i;
    for (i = 0; i < LINE_WIDTH; i++) {
        printf("-");
    }
    printf("\n");
}

int main() {
    char text[] = "x = 35";

    line();
    left(text);
    blank();
    center(text);
    blank();
    right(text);
    line();

    return 0;
}
