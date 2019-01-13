#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expression {
    int x;
    int y;
    int z;
};

struct player {
    char name[256];
    char proceed;
    char r;
    int e;
};

int check(struct expression exp, char op) {
    int mul;
    int sub;
    int sum;

    mul = (exp.x * exp.y) == exp.z;
    sub = (exp.x - exp.y) == exp.z;
    sum = (exp.x + exp.y) == exp.z;

    switch (op) {
        case '+':
            return sum;
        case '-':
            return sub;
        case '*':
            return mul;
        case 'I':
            if (!sum && !mul && !sub) {
                return 1;
            }
    }

    return 0;
}

int compare(const void *a, const void *b) {
    struct player *pa = (struct player *) a;
    struct player *pb = (struct player *) b;
    return strcmp(pa->name, pb->name);
}

int main() {
    struct expression games[50];
    struct player answers[50];
    int eliminated;
    int all;
    int none;
    int i;
    int j;
    int t;

    while (scanf("%d", &t) != EOF) {
        for (i = 0; i < t; i++) {
            scanf("%d %d=%d", &games[i].x, &games[i].y, &games[i].z);
        }

        all = 1;
        none = 1;
        eliminated = 0;
        for (i = 0; i < t; i++) {
            scanf("%s %d %c", answers[i].name, &answers[i].e, &answers[i].r);
            j = answers[i].e - 1;
            answers[i].proceed = check(games[j], answers[i].r);
            if (answers[i].proceed == 1) {
                none = 0;
            } else {
                all = 0;
                eliminated++;
            }
        }

        if (all == 1) {
            printf("You Shall All Pass!");
        } else if (none == 1) {
            printf("None Shall Pass!");
        } else {
            qsort(answers, t, sizeof(struct player), compare);
            for (i = 0; i < t; i++) {
                if (answers[i].proceed == 0) {
                    printf("%s", answers[i].name);
                    eliminated--;
                    if (eliminated > 0) {
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }

    return 0;
}
