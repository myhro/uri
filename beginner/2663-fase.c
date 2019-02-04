#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *) b - *(int *) a;
}

int main() {
    int contenders[1001];
    int count;
    int i;
    int k;
    int n;

    scanf("%d", &n);
    scanf("%d", &k);
    for (i = 0; i < n; i++) {
        scanf("%d", &contenders[i]);
    }

    qsort(contenders, n, sizeof(int), compare);
    count = 0;
    i = k;
    while (contenders[i] == contenders[k-1]) {
        count++;
        i++;
    }
    printf("%d\n", count + k);

    return 0;
}
