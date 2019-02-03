#include <stdio.h>

#define NEIGHBOURS 4

const int columns[NEIGHBOURS] = {1, -1, 0, 0};
const int rows[NEIGHBOURS] = {0, 0, 1, -1};

int islegal(int m[][16], int n, int i, int j) {
    return (i >= 0) && (j >= 0) && (i < n) && (j < n) && (m[i][j] == 0);
}

void dfs(int m[][16], int n, int i, int j) {
    int c;
    int k;
    int r;

    m[i][j] = 1;
    for (k = 0; k < NEIGHBOURS; k++) {
        c = j + columns[k];
        r = i + rows[k];
        if (islegal(m, n, r, c)) {
            dfs(m, n, r, c);
        }
    }
}

int count_zeroes(int m[][16], int n) {
    int total;
    int i;
    int j;

    for (i = 0; i < n; i++) {
        if (m[0][i] == 0) {
            dfs(m, n, 0, i);
        }
    }
    for (i = 0; i < n; i++) {
        if (m[n-1][i] == 0) {
            dfs(m, n, n-1, i);
        }
    }
    for (i = 0; i < n; i++) {
        if (m[i][0] == 0) {
            dfs(m, n, i, 0);
        }
    }
    for (i = 0; i < n; i++) {
        if (m[i][n-1] == 0) {
            dfs(m, n, i, n-1);
        }
    }

    total = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (m[i][j] == 0) {
                total++;
            }
        }
    }

    return total;
}

int main() {
    float area;
    int grid[16][16];
    int zeroes;
    int ones;
    int i;
    int j;
    int l;
    int q;

    scanf("%d", &q);
    while (q) {
        scanf("%d", &l);
        ones = 0;
        for (i = 0; i < l; i++) {
            for (j = 0; j < l; j++) {
                scanf("%d", &grid[i][j]);
                if (grid[i][j] == 1) {
                    ones++;
                }
            }
        }
        zeroes = count_zeroes(grid, l);
        area = (ones + zeroes) / 2.0;
        printf("%.2f\n", area);
        q--;
    }

    return 0;
}
