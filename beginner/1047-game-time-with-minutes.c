#include <stdio.h>

int main() {
    int hours;
    int minutes;
    int fh;
    int fm;
    int ih;
    int im;

    scanf("%d %d %d %d", &ih, &im, &fh, &fm);

    hours = fh - ih;
    if ((hours <= 0) && (fm <= im)) {
        hours += 24;
    }

    minutes = fm - im;
    if (minutes < 0) {
        minutes += 60;
        hours -= 1;
    }

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", hours, minutes);

    return 0;
}
