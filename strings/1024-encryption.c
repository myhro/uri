#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
    char s[1024];
    char tmp;
    int i;
    int l;
    int n;
    int r;

    scanf("%d", &n);
    while (n > 0) {
        scanf(" %[^\n]s", s);
        l = 0;
        r = strlen(s) - 1;
        for (i = 0; i <= r; i++) {
            if (islower(s[i]) || isupper(s[i])) {
                s[i] += 3;
            }
        }
        while (l <= r) {
            tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            s[r] -= 1;
            l++;
            r--;
        }
        printf("%s\n", s);
        n--;
    }

    return 0;
}
