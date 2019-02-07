#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct vertex {
    struct vertex *next;
    int vertex;
    int weight;
};

struct graph {
    struct vertex **edges;
    int *distances;
    int *weights;
    int vertexes;
};

void insert_edge(struct vertex **v, int u, int w) {
    struct vertex *cur;
    struct vertex *tmp;

    tmp = (struct vertex *) malloc(sizeof(struct vertex));
    tmp->next = NULL;
    tmp->vertex = u;
    tmp->weight = w;

    if (*v == NULL) {
        *v = tmp;
    } else {
        cur = *v;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = tmp;
    }
}

void add_edge(struct graph *g, int u, int v, int w) {
    insert_edge(&g->edges[u], v, w);
}

int empty(struct vertex *head) {
    return head == NULL;
}

void insert_pq(struct vertex **head, int v, int w) {
    struct vertex *cur;
    struct vertex *tmp;

    tmp = (struct vertex *) malloc(sizeof(struct vertex));
    tmp->next = NULL;
    tmp->vertex = v;
    tmp->weight = w;

    if (*head == NULL) {
        *head = tmp;
    } else if ((*head)->weight > w) {
        tmp->next = *head;
        *head = tmp;
    } else {
        cur = *head;
        while ((cur->next != NULL) && (cur->next->weight < w)) {
            cur = cur->next;
        }
        tmp->next = cur->next;
        cur->next = tmp;
    }
}

struct graph* new_graph(int n) {
    struct graph *tmp;
    int i;

    tmp = (struct graph *) malloc(sizeof(struct graph));
    tmp->distances = (int *) malloc(n * sizeof(int));
    tmp->edges = (struct vertex **) malloc(n * sizeof(struct vertex *));
    tmp->weights = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        tmp->distances[i] = INT_MAX;
        tmp->edges[i] = NULL;
        tmp->weights[i] = 0;
    }
    tmp->vertexes = n;

    return tmp;
}

struct vertex pop(struct vertex **head) {
    struct vertex *tmp;
    struct vertex r;

    r.vertex = -1;
    r.weight = -1;
    if (*head == NULL) {
        return r;
    }

    r.vertex = (*head)->vertex;
    r.weight = (*head)->weight;
    tmp = (*head)->next;
    free(*head);
    *head = tmp;

    return r;
}

void set_vertex_weight(struct graph *g, int u, int w) {
    g->weights[u] = w;
}

void shortest_path(struct graph *g, int src) {
    struct vertex *queue;
    struct vertex *tmp;
    int u;
    int v;
    int w;

    queue = NULL;
    insert_pq(&queue, src, 0);
    g->distances[src] = 0;

    while (!empty(queue)) {
        u = pop(&queue).vertex;
        tmp = g->edges[u];
        while (tmp != NULL) {
            v = tmp->vertex;
            w = tmp->weight;
            if (g->distances[v] > (g->distances[u] + g->weights[u] + w)) {
                g->distances[v] = g->distances[u] + g->weights[u] + w;
                insert_pq(&queue, v, g->distances[v]);
            }
            tmp = tmp->next;
        }
    }
}

int main() {
    struct graph *g;
    int total;
    int i;
    int j;
    int n;
    int w;

    while (scanf("%d", &n) != EOF) {
        total = 2 * n + 2;
        g = new_graph(total);
        j = 0;
        for (i = 0; i < 2; i++) {
            scanf("%d", &w);
            add_edge(g, j, j+i+1, w);
        }
        j = 1;
        for (i = 0; i < n; i++) {
            scanf("%d", &w);
            if (i != (n - 1)) {
                add_edge(g, j, j+2, 0);
            }
            set_vertex_weight(g, j, w);
            j += 2;
        }
        j = 2;
        for (i = 0; i < n; i++) {
            scanf("%d", &w);
            if (i != (n - 1)) {
                add_edge(g, j, j+2, 0);
            }
            set_vertex_weight(g, j, w);
            j += 2;
        }
        j = 1;
        for (i = 0; i < (n - 1); i++) {
            scanf("%d", &w);
            add_edge(g, j, j+3, w);
            j += 2;
        }
        j = 2;
        for (i = 0; i < (n - 1); i++) {
            scanf("%d", &w);
            add_edge(g, j, j+1, w);
            j += 2;
        }
        j = total - 1;
        for (i = 2; i > 0; i--) {
            scanf("%d", &w);
            add_edge(g, j-i, j, w);
        }
        shortest_path(g, 0);
        printf("%d\n", g->distances[total-1]);
    }

    return 0;
}
