#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define HASH_SIZE 10000

struct item {
    char token[3];
    int count;
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

void init(struct item *map) {
    int i;

    for (i = 0; i < HASH_SIZE; i++) {
        map[i].count = 0;
        map[i].token[0] = '\0';
    }
}

int insert(struct item *map, char *tok, int max) {
    unsigned int h;
    h = hash(tok);

    if (map[h].count == 0) {
        map[h].count = 1;
        strcpy(map[h].token, tok);
    } else {
        map[h].count++;
    }

    if (map[h].count > max) {
        max = map[h].count;
    }

    return max;
}

int main() {
    struct item tokens[HASH_SIZE];
    char input[100001];
    char *answer;
    char tok[3];
    int max;
    int i;
    int n;

    init(tokens);
    scanf("%[^\n]s", input);
    max = 0;
    n = strlen(input);
    for (i = 0; i < (n - 1); i++) {
        tok[0] = tolower(input[i]);
        tok[1] = tolower(input[i+1]);
        tok[2] = '\0';
        max = insert(tokens, tok, max);
    }
    answer = NULL;
    for (i = 0; i < HASH_SIZE; i++) {
        if (tokens[i].count == max) {
            if (answer == NULL) {
                answer = tokens[i].token;
            } else if (strcmp(tokens[i].token, answer) < 0) {
                answer = tokens[i].token;
            }
        }
    }
    printf("%s:%d\n", answer, max);

    return 0;
}
