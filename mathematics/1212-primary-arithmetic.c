#include <stdio.h>
#include <string.h>

int dec(char *n, int i) {
    return n[i] - '0';
}

int iszero(char *n) {
    return strcmp(n, "0") == 0;
}

void zeropad(char *n) {
    char tmp[16];
    int diff;
    int i;

    diff = 10 - strlen(n);
    strcpy(tmp, n);
    for (i = 0; i < diff; i++) {
        n[i] = '0';
    }
    for (i = diff; i < 10; i++) {
        n[i] = tmp[i - diff];
    }
    n[i] = '\0';
}

int main() {
    char input[2][16];
    int remain;
    int carry;
    int sum;
    int i;

    while (scanf("%s %s", input[0], input[1]) != EOF) {
        if (iszero(input[0]) && iszero(input[1])) {
            break;
        }
        zeropad(input[0]);
        zeropad(input[1]);

        carry = 0;
        remain = 0;
        for (i = 10 - 1; i >= 0; i--) {
            sum = dec(input[0], i) + dec(input[1], i) + remain;
            if (sum >= 10) {
                carry++;
                remain = 1;
            } else {
                remain = 0;
            }
        }

        if (carry == 0) {
            printf("No carry operation.\n");
        } else if (carry == 1) {
            printf("1 carry operation.\n");
        } else {
            printf("%d carry operations.\n", carry);
        }
    }

    return 0;
}
