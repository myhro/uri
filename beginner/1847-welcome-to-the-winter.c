#include <stdio.h>

void happy() {
    printf(":)\n");
}

void sad() {
    printf(":(\n");
}

int main() {
    int a;
    int b;
    int c;
    int d1;
    int d2;

    scanf("%d %d %d", &a, &b, &c);

    d1 = b - a;
    d2 = c - b;

    if ((d1 < 0) && (d2 >= 0)) {
        happy();
    } else if ((d1 > 0) && (d2 <= 0)) {
        sad();
    } else if ((d1 > 0) && (d2 > 0) && (d2 < d1)) {
        sad();
    } else if ((d1 > 0) && (d2 > 0) && (d2 >= d1)) {
        happy();
    } else if ((d1 < 0) && (d2 < 0) && (d2 > d1)) {
        happy();
    } else if ((d1 < 0) && (d2 < 0) && (d2 >= d1)) {
        sad();
    } else if ((d1 == 0) && (d2 > 0)) {
        happy();
    } else {
        sad();
    }

    return 0;
}
