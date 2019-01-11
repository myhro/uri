#include <stdio.h>

struct time {
    int days;
    int hours;
    int mins;
    int secs;
};

int main() {
    struct time initial;
    struct time final;
    struct time result;

    scanf("Dia %d", &initial.days);
    scanf("%d : %d : %d", &initial.hours, &initial.mins, &initial.secs);
    getchar();
    scanf("Dia %d", &final.days);
    scanf("%d : %d : %d", &final.hours, &final.mins, &final.secs);

    result.secs = (final.secs - initial.secs);
    result.mins = (final.mins - initial.mins);
    result.hours = (final.hours - initial.hours);
    result.days = (final.days - initial.days);

    if (result.secs < 0) {
        result.secs += 60;
        result.mins--;
    }
    if (result.mins < 0) {
        result.mins += 60;
        result.hours--;
    }
    if (result.hours < 0) {
        result.hours += 24;
        result.days--;
    }

    printf("%d dia(s)\n", result.days);
    printf("%d hora(s)\n", result.hours);
    printf("%d minuto(s)\n", result.mins);
    printf("%d segundo(s)\n", result.secs);

    return 0;
}
