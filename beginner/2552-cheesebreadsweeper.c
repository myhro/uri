#include <stdio.h>

int isvalid(int n, int m, int i, int j) {
    return (i >= 0) && (j >= 0) && (i < n) && (j < m);
}

int count_neighbours(int board[][100], int n, int m, int i, int j) {
    int count;

    count = 0;
    if (isvalid(n, m, i-1, j) && (board[i-1][j] == 1)) {
        count++;
    }
    if (isvalid(n, m, i, j+1) && (board[i][j+1] == 1)) {
        count++;
    }
    if (isvalid(n, m, i+1, j) && (board[i+1][j] == 1)) {
        count++;
    }
    if (isvalid(n, m, i, j-1) && (board[i][j-1] == 1)) {
        count++;
    }

    return count;
}

int main() {
    int board[100][100];
    int n;
    int m;
    int i;
    int j;

    while (scanf("%d %d", &n, &m) != EOF) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                scanf("%d", &board[i][j]);
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (board[i][j] == 1) {
                    printf("9");
                } else {
                    printf("%d", count_neighbours(board, n, m, i, j));
                }
            }
            printf("\n");
        }
    }

    return 0;
}
