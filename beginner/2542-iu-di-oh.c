#include <stdio.h>

int main() {
    int marcos[100][100];
    int leonardo[100][100];
    int cl;
    int cm;
    int a;
    int i;
    int j;
    int l;
    int m;
    int n;

    while (scanf("%d", &n) != EOF) {
        scanf("%d %d", &m, &l);
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                scanf("%d", &marcos[i][j]);
            }
        }
        for (i = 0; i < l; i++) {
            for (j = 0; j < n; j++) {
                scanf("%d", &leonardo[i][j]);
            }
        }
        scanf("%d %d", &cm, &cl);
        scanf("%d", &a);
        if (marcos[cm-1][a-1] > leonardo[cl-1][a-1]) {
            printf("Marcos\n");
        } else if (leonardo[cl-1][a-1] > marcos[cm-1][a-1]) {
            printf("Leonardo\n");
        } else {
            printf("Empate\n");
        }
    }

    return 0;
}
