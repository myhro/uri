#include <stdio.h>

#define CHANGES 7
 
int main() {
    int notes[CHANGES] = {100, 50, 20, 10, 5, 2, 1};
    int result[101] = {0};
    int note;
    int tmp;
    int i;
    int n;

    scanf("%d", &n);

    tmp = n;
    for (i = 0; i < CHANGES; i++) {
        note = notes[i];
        while (tmp >= note) {
            result[note] += 1;
            tmp -= note;
        }
    }

    printf("\
%d\n\
%d nota(s) de R$ 100,00\n\
%d nota(s) de R$ 50,00\n\
%d nota(s) de R$ 20,00\n\
%d nota(s) de R$ 10,00\n\
%d nota(s) de R$ 5,00\n\
%d nota(s) de R$ 2,00\n\
%d nota(s) de R$ 1,00\n\
",
        n,
        result[100],
        result[50],
        result[20],
        result[10],
        result[5],
        result[2],
        result[1]
    );

    return 0;
}
