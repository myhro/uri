#include <math.h>
#include <stdio.h>
#include <string.h>

int prime(int n) {
    int i;
    int r;

    if (n == 2) {
        return 1;
    } else if ((n == 1) || ((n % 2) == 0)) {
        return 0;
    }

    r = ceil(sqrt(n)) + 1;
    for (i = 3; i < r; i++) {
        if ((n % i) == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char number[256];
    char super;
    int d;
    int i;
    int l;
    int n;

    while (scanf("%d", &n) != EOF) {
        if (prime(n) == 0) {
            printf("Nada\n");
        } else {
            super = 1;
            sprintf(number, "%d", n);
            l = strlen(number);
            for (i = 0; i < l; i++) {
                d = number[i] - '0';
                if (prime(d) == 0) {
                    super = 0;
                    printf("Primo\n");
                    break;
                }
            }
            if (super == 1) {
                printf("Super\n");
            }
        }
    }

    return 0;
}
