#include <stdio.h>
#include <stdlib.h>

#define FIB_SIZE 30
#define NOT_SIZE 100100

int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int fib[FIB_SIZE];
    int not[NOT_SIZE];
    int i;
    int j;
    int k;
    int *r;

    scanf("%d", &k);

    fib[0] = 0;
    fib[1] = 1;
    for (i = 2; i < FIB_SIZE; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    j = 0;
    for (i = 0; i < NOT_SIZE; i++) {
        r = bsearch(&i, fib, FIB_SIZE, sizeof(int), compare);
        if (r != NULL) {
            continue;
        }
        not[j] = i;
        j++;
        if (j == k) {
            break;
        }
    }

    printf("%d\n", not[k-1]);

    return 0;
}
