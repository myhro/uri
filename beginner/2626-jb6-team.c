#include <stdio.h>
#include <string.h>

#define ROCK 1
#define PAPER 2
#define SCISSORS 3
#define STR_SIZE 256

struct play {
    int chosen;
    int beat;
    int lose;
};

int who_won(struct play p1, struct play p2) {
    if (p1.chosen == p2.lose) {
        return 0;
    } else if (p2.chosen == p1.lose) {
        return 1;
    }
    return -1;
}

int jokenpo(char players[][STR_SIZE]) {
    struct play bets[3];
    int i;
    int winner1;
    int winner2;
    int winner3;

    for (i = 0; i < 3; i++) {
        if (strcmp(players[i], "pedra") == 0) {
            bets[i].chosen = ROCK;
            bets[i].beat = SCISSORS;
            bets[i].lose = PAPER;
        } else if (strcmp(players[i], "papel") == 0) {
            bets[i].chosen = PAPER;
            bets[i].beat = ROCK;
            bets[i].lose = SCISSORS;
        } else if (strcmp(players[i], "tesoura") == 0) {
            bets[i].chosen = SCISSORS;
            bets[i].beat = PAPER;
            bets[i].lose = ROCK;
        }
    }

    winner1 = who_won(bets[0], bets[1]);
    winner2 = who_won(bets[1], bets[2]);
    winner3 = who_won(bets[0], bets[2]);

    if ((winner1 == 0) && (winner3 == 0)) {
        return 0;
    } else if ((winner1 == 1) && (winner2 == 0)) {
        return 1;
    } else if ((winner2 == 1) && (winner3 == 1)) {
        return 2;
    }

    return -1;
}

int main() {
    char input[3][STR_SIZE];
    int r;

    while(scanf("%s %s %s", input[0], input[1], input[2]) != EOF) {
        r = jokenpo(input);
        if (r == 0) {
            printf("Os atributos dos monstros vao ser inteligencia, sabedoria...\n");
        } else if (r == 1) {
            printf("Iron Maiden's gonna get you, no matter how far!\n");
        } else if (r == 2) {
            printf("Urano perdeu algo muito precioso...\n");
        } else {
            printf("Putz vei, o Leo ta demorando muito pra jogar...\n");
        }
    }

    return 0;
}
