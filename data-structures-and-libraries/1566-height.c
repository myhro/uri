#include <stdio.h>

#define ARR_MAX 256

int main() {
    int heights[ARR_MAX];
    int first;
    int tmp;
    int nc;
    int n;
    int i;
    int j;

    scanf("%d", &nc);
    for (i = 0; i < nc; i++) {
        for (j = 0; j < ARR_MAX; j++) {
            heights[j] = 0;
        }
        scanf("%d", &n);
        for (j = 0; j < n; j++) {
            scanf("%d", &tmp);
            heights[tmp]++;
        }
        first = 1;
        for (j = 0; j < ARR_MAX; j++) {
            if (heights[j] != 0) {
                while (heights[j]) {
                    if (!first) {
                        printf(" ");
                    }
                    first = 0;
                    printf("%d", j);
                    heights[j]--;
                }
            }
        }
        printf("\n");
    }

    return 0;
}
