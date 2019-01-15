#include <stdio.h>
#include <string.h>

#define RAIN 1
#define SUN 2

int weather(char *str) {
    if (strcmp(str, "chuva") == 0) {
        return RAIN;
    }
    return SUN;
}

int main() {
    char input[256];
    int left_home;
    int left_office;
    int home;
    int office;
    int uh;
    int uo;
    int i;
    int n;

    left_home = 0;
    left_office = 0;
    uh = 0;
    uo = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", input);
        home = weather(input);
        scanf("%s", input);
        office = weather(input);
        if (home == RAIN) {
            if (left_home == 0) {
                uh++;
            } else {
                left_home--;
            }
            left_office++;
        }
        if (office == RAIN) {
            if (left_office == 0) {
                uo++;
            } else {
                left_office--;
            }
            left_home++;
        }
    }
    printf("%d %d\n", uh, uo);

    return 0;
}
