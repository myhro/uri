#include <stdio.h>

int main() {
    char dates[50][16];
    int people[50][50];
    int found;
    int d;
    int i;
    int j;
    int n;

    while (scanf("%d %d", &n, &d) != EOF) {
        for (i = 0; i < d; i++) {
            scanf("%s", dates[i]);
            for (j = 0; j < n; j++) {
                scanf("%d", &people[i][j]);
            }
        }
        for (i = 0; i < d; i++) {
            found = 1;
            for (j = 0; j < n; j++) {
                if (people[i][j] == 0) {
                    found = 0;
                    break;
                }
            }
            if (found) {
                printf("%s\n", dates[i]);
                break;
            }
        }
        if (!found) {
            printf("Pizza antes de FdI\n");
        }
    }

    return 0;
}
