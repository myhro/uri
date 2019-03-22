#include <stdio.h>

#define SIZE 100001

int TREE[SIZE];

int sum(int i) {
    int total;

    total = 0;
    while (i > 0) {
        total += TREE[i];
        i -= i & (-i);
    }

    return total;
}

void add(int i, int k, int n) {
    while(i < n) {
        TREE[i] += k;
        i += i & (-i);
    }
}

int count(int *v, int n) {
    int total;
    int i;

    for (i = 0; i < n; i++) {
        TREE[i] = 0;
    }

    total = 0;
    for (i = n - 1; i >= 0; i--) {
        total += sum(v[i] - 1);
        add(v[i], 1, n);
    }

    return total;
}

int main() {
    int input[SIZE];
    int i;
    int n;

    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        for (i = 0; i < n; i++) {
            scanf("%d", &input[i]);
        }
        if ((count(input, n) % 2) == 0) {
            printf("Carlos\n");
        } else {
            printf("Marcelo\n");
        }
    }

    return 0;
}
