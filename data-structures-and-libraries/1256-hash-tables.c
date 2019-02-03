#include <stdio.h>
#include <stdlib.h>

#define MAX_HASH 101

struct key {
    struct key *next;
    int value;
};

void clean(struct key **dict, int n) {
    struct key *tmp;
    int i;
    for (i = 0; i < n; i++) {
        while (dict[i] != NULL) {
            tmp = dict[i]->next;
            free(dict[i]);
            dict[i] = tmp;
        }
    }
}

void init(struct key **dict) {
    int i;
    for (i = 0; i < MAX_HASH; i++) {
        dict[i] = NULL;
    }
}

void insert(struct key **dict, int n, int v) {
    struct key *cur;
    struct key *tmp;
    int h;

    tmp = (struct key *) malloc(sizeof(struct key));
    tmp->next = NULL;
    tmp->value = v;

    h = v % n;
    if (dict[h] == NULL) {
        dict[h] = tmp;
    } else {
        cur = dict[h];
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = tmp;
    }
}

void print(struct key **dict, int n) {
    struct key *tmp;
    int i;
    for (i = 0; i < n; i++) {
        printf("%d -> ", i);
        tmp = dict[i];
        while (tmp != NULL) {
            printf("%d -> ", tmp->value);
            tmp = tmp->next;
        }
        printf("\\\n");
    }
}

int main() {
    struct key *dict[MAX_HASH];
    int tmp;
    int c;
    int i;
    int m;
    int n;

    init(dict);
    scanf("%d", &n);
    while (n) {
        scanf("%d %d", &m, &c);
        for (i = 0; i < c; i++) {
            scanf("%d", &tmp);
            insert(dict, m, tmp);
        }
        print(dict, m);
        clean(dict, m);
        n--;
        if (n) {
            printf("\n");
        }
    }

    return 0;
}
