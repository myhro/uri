#include <stdio.h>

#define HASH_SIZE 102
#define METADATA HASH_SIZE - 1
#define KEYS_SIZE 200

void clean(int dict[][KEYS_SIZE], int n) {
    int i;
    int j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < KEYS_SIZE; j++) {
            if (dict[i][j] == 0) {
                break;
            }
            dict[i][j] = 0;
        }
        dict[METADATA][i] = 0;
    }
}

void insert(int dict[][KEYS_SIZE], int n, int v) {
    int last;
    int h;

    h = v % n;
    last = dict[METADATA][h];
    dict[h][last] = v;
    dict[METADATA][h]++;
}

void print(int dict[][KEYS_SIZE], int n) {
    int i;
    int j;
    for (i = 0; i < n; i++) {
        printf("%d -> ", i);
        for (j = 0; j < KEYS_SIZE; j++) {
            if (dict[i][j] == 0) {
                break;
            }
            printf("%d -> ", dict[i][j]);
        }
        printf("\\\n");
    }
}

int main() {
    int dict[HASH_SIZE][KEYS_SIZE] = {0};
    int tmp;
    int c;
    int i;
    int m;
    int n;

    scanf("%d", &n);
    while (n) {
        scanf("%d %d", &m, &c);
        for (i = 0; i < c; i++) {
            scanf("%d", &tmp);
            insert(dict, m, tmp);
        }
        print(dict, m);
        clean(dict, m);
        n--;
        if (n) {
            printf("\n");
        }
    }

    return 0;
}
