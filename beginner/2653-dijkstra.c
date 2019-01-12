#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 100000

struct key {
    char *value;
    struct key *next;
};

unsigned int hash(char *str) {
    unsigned int h;
    char c;

    c = *str;
    h = 1;
    while (c != '\0') {
        h = h * 33 + c;
        c = *str;
        str++;
    }

    return h % HASH_SIZE;
}

struct key *new_key(char *str) {
    struct key *tmp;
    int n;

    n = strlen(str);
    tmp = (struct key *) malloc(sizeof(struct key));
    tmp->next = NULL;
    tmp->value = (char *) malloc(sizeof(char) * (n + 1));
    strncpy(tmp->value, str, n);
    tmp->value[n] = '\0';

    return tmp;
}

void add_key(struct key **dict, char *str) {
    struct key *lookup;
    struct key *tmp;
    int h;

    h = hash(str);
    tmp = new_key(str);
    if (dict[h] == NULL) {
        dict[h] = tmp;
    } else {
        lookup = dict[h];
        while (lookup != NULL) {
            if (strcmp(lookup->value, str) == 0) {
                return;
            } else if (lookup->next == NULL) {
                lookup->next = tmp;
                return;
            }
            lookup = lookup->next;
        }
    }
}

int len_dict(struct key **dict) {
    struct key *lookup;
    int i;
    int n;

    n = 0;
    for (i = 0; i < HASH_SIZE; i++) {
        if (dict[i] != NULL) {
            lookup = dict[i];
            while (lookup != NULL) {
                n++;
                lookup = lookup->next;
            }
        }
    }

    return n;
}

int main() {
    struct key *dict[HASH_SIZE];
    char input[65536];
    int i;

    for (i = 0; i < HASH_SIZE; i++) {
        dict[i] = NULL;
    }

    while(scanf("%s", input) != EOF) {
        add_key(dict, input);
    }

    printf("%d\n", len_dict(dict));

    return 0;
}
