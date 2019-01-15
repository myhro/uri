#include <stdio.h>
#include <stdlib.h>

#define SEQ_SIZE 1000001

long long sum(int *list, int n) {
    long long r;
    int i;

    r = 0;
    for (i = 0; i < n; i++) {
        r += list[i];
    }

    return r;
}

int min(int x, int y) {
    if (x < y) {
        return x;
    }
    return y;
}


int main() {
    long long ldiff;
    long long rdiff;
    long long half;
    long long left;
    long long right;
    int seq[SEQ_SIZE];
    int r1;
    int r2;
    int i;
    int j;
    int n;

    while (scanf("%d", &n) != EOF) {
        left = 0;
        right = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &seq[i]);
        }
        if (n == 1) {
            printf("%d\n", seq[0]);
            continue;
        }
        half = sum(seq, n) / 2;

        i = 0;
        while (left < half) {
            left += seq[i];
            i++;
        }
        j = n - 1;
        while (right < half) {
            right += seq[j];
            j--;
        }

        if ((half == 1) && (left == 1) && (right == 1)) {
            if (n == 2) {
                printf("0\n");
            } else {
                printf("1\n");
            }
            continue;
        } else if ((left == half) || (right == half)) {
            printf("%lld\n", right - left);
            continue;
        }

        rdiff = 0;
        if (j < (n - 2)) {
            rdiff = seq[j+1];
        }
        ldiff = 0;
        if (i > 1) {
            ldiff = seq[i-1];
        }

        r1 = right - rdiff - left;
        r2 = left - ldiff - right;
        printf("%d\n", min(abs(r1), abs(r2)));
    }

    return 0;
}
