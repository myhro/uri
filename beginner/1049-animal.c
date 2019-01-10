#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct animal {
    char text[16];
    struct animal *left;
    struct animal *right;
};

struct animal* new_animal(char *text) {
    struct animal *a;
    a = (struct animal *) malloc(sizeof(struct animal));
    strcpy(a->text, text);
    a->left = NULL;
    a->right = NULL;
    return a;
}

struct animal* search_animal(struct animal *a, char *text) {
    if (strcmp(a->left->text, text) == 0) {
        return a->left;
    } else if (strcmp(a->right->text, text) == 0) {
        return a->right;
    }
    return NULL;
}

int main() {
    struct animal *root;
    struct animal *tmp;
    char input[3][16];
    int i;

    root = new_animal("root");
    root->left = new_animal("vertebrado");
    root->right = new_animal("invertebrado");

    // vertebrado
    root->left->left = new_animal("ave");
    root->left->right = new_animal("mamifero");
    // invertebrado
    root->right->left = new_animal("inseto");
    root->right->right = new_animal("anelideo");

    // ave
    root->left->left->left = new_animal("carnivoro");
    root->left->left->right = new_animal("onivoro");
    // mamifero
    root->left->right->left = new_animal("onivoro");
    root->left->right->right = new_animal("herbivoro");
    // inseto
    root->right->left->left = new_animal("hematofago");
    root->right->left->right = new_animal("herbivoro");
    // anelideo
    root->right->right->left = new_animal("hematofago");
    root->right->right->right = new_animal("onivoro");

    // ave.carnivoro
    root->left->left->left->left = new_animal("aguia");
    // ave.onivoro
    root->left->left->right->left = new_animal("pomba");
    // mamifero.onivoro
    root->left->right->left->left = new_animal("homem");
    // mamifero.herbivoro
    root->left->right->right->left = new_animal("vaca");
    // inseto.hematofago
    root->right->left->left->left = new_animal("pulga");
    // inseto.herbivoro
    root->right->left->right->left = new_animal("lagarta");
    // anelideo.hematofago
    root->right->right->left->left = new_animal("sanguessuga");
    // anelideo.onivoro
    root->right->right->right->left = new_animal("minhoca");

    for (i = 0; i < 3; i++) {
        scanf("%s", input[i]);
    }

    tmp = search_animal(root, input[0]);
    tmp = search_animal(tmp, input[1]);
    tmp = search_animal(tmp, input[2]);

    printf("%s\n", tmp->left->text);

    return 0;
}
