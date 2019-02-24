#include <stdio.h>
#include <string.h>

int main() {
    char s[64];
    char t[64];
    char a;
    char b;
    int g[26][26];
    int match;
    int i;
    int j;
    int k;
    int m;
    int n;

    for (i = 0; i < 26; i++) {
        for (j = 0; j < 26; j++) {
            g[i][j] = 9999;
        }
    }

    scanf("%d %d", &m, &n);
    for (i = 0; i < m; i++) {
        scanf(" %c %c", &a, &b);
        g[a - 'a'][b - 'a'] = 1;
    }

    for (k = 0; k < 26; k++) {
        for (i = 0; i < 26; i++) {
            for (j = 0; j < 26; j++) {
                if (g[i][j] > (g[i][k] + g[k][j])) {
                    g[i][j] = 1;
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        match = 1;
        scanf("%s %s", s, t);
        k = strlen(s);
        if (k != strlen(t)) {
            printf("no\n");
            continue;
        }
        for (j = 0; j < k; j++) {
            a = s[j];
            b = t[j];
            if ((a != b) && (g[a - 'a'][b - 'a'] != 1)) {
                match = 0;
                break;
            }
        }
        if (match) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

    /* for (i = 0; i < 26; i++) { */
    /*     printf("%c -> ", i + 'a'); */
    /*     for (j = 0; j < 26; j++) { */
    /*         if (g[i][j] == 1) { */
    /*             printf("%c ", j + 'a'); */
    /*         } else { */
    /*             printf("- "); */
    /*         } */
    /*     } */
    /*     printf("\n"); */
    /* } */

    return 0;
}
