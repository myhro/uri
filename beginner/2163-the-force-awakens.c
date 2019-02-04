#include <stdio.h>

int main() {
    int terrain[1000][1000];
    int found;
    int i;
    int j;
    int m;
    int n;

    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &terrain[i][j]);
        }
    }
    found = 0;
    for (i = 1; i < (n - 1); i++) {
        for (j = 1; j < (m - 1); j++) {
            if ((terrain[i][j] == 42) &&
                (terrain[i-1][j] == 7) &&
                (terrain[i-1][j+1] == 7) &&
                (terrain[i][j+1] == 7) &&
                (terrain[i+1][j+1] == 7) &&
                (terrain[i+1][j] == 7) &&
                (terrain[i+1][j-1] == 7) &&
                (terrain[i][j-1] == 7) &&
                (terrain[i-1][j-1] == 7)) {
                printf("%d %d\n", i + 1, j + 1);
                found = 1;
                break;
            }
        }
    }
    if (!found) {
        printf("0 0\n");
    }

    return 0;
}
