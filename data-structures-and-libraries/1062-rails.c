#include <stdio.h>

struct stack {
    int arr[1024];
    int size;
};

int empty(struct stack *s) {
    return s->size == 0;
}

void init(struct stack *s) {
    s->size = 0;
}

void pop(struct stack *s) {
    if (s->size > 0) {
        s->size--;
    }
}

void push(struct stack *s, int x) {
    s->arr[s->size] = x;
    s->size++;
}

int top(struct stack *s) {
    return s->arr[s->size - 1];
}

int main() {
    struct stack a;
    struct stack b;
    int valid;
    int run;
    int tmp;
    int i;
    int n;

    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        run = 1;
        while (run) {
            init(&a);
            init(&b);
            for (i = n; i > 0; i--) {
                push(&a, i);
            }
            tmp = 0;
            valid = 1;
            for (i = 0; i < n; i++) {
                scanf("%d", &tmp);
                if (tmp == 0) {
                    run = 0;
                    break;
                }
                if (!valid) {
                    continue;
                }
                while(!empty(&a) && (top(&a) < tmp)) {
                    push(&b, top(&a));
                    pop(&a);
                }
                if (!empty(&a) && (top(&a) == tmp)) {
                    pop(&a);
                } else if (!empty(&b) && (top(&b) == tmp)) {
                    pop(&b);
                } else {
                    valid = 0;
                }
            }
            if (tmp != 0) {
                if (valid) {
                    printf("Yes\n");
                } else {
                    printf("No\n");
                }
            }
        }
        printf("\n");
    }

    return 0;
}
