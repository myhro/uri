#include <ctype.h>
#include <stdio.h>
#include <string.h>

int tail(char c) {
    if (isdigit(c) || islower(c)) {
        return 1;
    }
    return 0;
}

int check(char *experiment, char compounds[][256], int n) {
    char *sub;
    int proceed;
    int i;
    int l;

    proceed = 1;
    for (i = 0; i < n; i++) {
        l = strlen(compounds[i]);
        sub = strstr(experiment, compounds[i]);
        if ((sub != NULL) && (!tail(sub[l]))) {
            proceed = 0;
            break;
        }
    }

    return proceed;
}

int main() {
    char dangerous[64][256];
    char experiment[256];
    int ok;
    int i;
    int j;
    int n;
    int t;
    int u;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &t);
        for (j = 0; j < t; j++) {
            scanf(" %[^\n]s", dangerous[j]);
        }
        scanf("%d", &u);
        for (j = 0; j < u; j++) {
            scanf(" %[^\n]s", experiment);
            ok = check(experiment, dangerous, t);
            if (ok == 1) {
                printf("Prossiga\n");
            } else {
                printf("Abortar\n");
            }
        }
        if (i != (n - 1)) {
            printf("\n");
        }
    }

    return 0;
}
