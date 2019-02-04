#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define PLATE_SIZE 8

int check_day(char *p) {
    int last;

    last = p[strlen(p)-1] - '0';
    switch(last) {
        case 1:
        case 2:
            return 0;
        case 3:
        case 4:
            return 1;
        case 5:
        case 6:
            return 2;
        case 7:
        case 8:
            return 3;
        case 9:
        case 0:
            return 4;
    }

    return -1;
}

int isvalid(char *p) {
    int i;

    if (strlen(p) != PLATE_SIZE) {
        return 0;
    }
    for (i = 0; i < 3; i++) {
        if (!isupper(p[i])) {
            return 0;
        }
    }
    if (p[3] != '-') {
        return 0;
    }
    for (i = 4; i < PLATE_SIZE; i++) {
        if (!isdigit(p[i])) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char days[5][10] = {"MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY"};
    char plate[101];
    int d;
    int n;

    scanf("%d", &n);
    while (n) {
        scanf("%s", plate);
        if (!isvalid(plate)) {
            printf("FAILURE\n");
        } else {
            d = check_day(plate);
            printf("%s\n", days[d]);
        }
        n--;
    }

    return 0;
}
