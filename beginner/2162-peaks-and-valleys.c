#include <stdio.h>

int main() {
    char pattern;
    int comparison;
    int current;
    int prev;
    int i;
    int n;

    scanf("%d", &n);
    scanf("%d", &prev);
    comparison = 0;
    pattern = 1;

    for (i = 1; i < n; i++) {
        scanf("%d", &current);
        if (current == prev) {
            pattern = 0;
            break;
        } else if (current < prev) {
            if (comparison < 0) {
                pattern = 0;
                break;
            }
            comparison = -1;
        } else {
            if (comparison > 0) {
                pattern = 0;
                break;
            }
            comparison = 1;
        }
        prev = current;
    }

    printf("%d\n", pattern);

    return 0;
}
