#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHANGES 6
 
int main() {
    int bills[CHANGES] = {100, 50, 20, 10, 5, 2};
    int coins[CHANGES] = {100, 50, 25, 10, 5, 1};
    int result_bills[101] = {0};
    int result_coins[101] = {0};
    int cents;
    int currency;
    int i;
    char value[256];
    char *split;

    scanf("%s", value);

    split = strtok(value, ".");
    currency = atoi(split);
    split = strtok(NULL, ".");
    cents = atoi(split);

    for (i = 0; i < CHANGES; i++) {
        while (currency >= bills[i]) {
            result_bills[bills[i]] += 1;
            currency -= bills[i];
        }
    }

    if (currency == 1) {
        result_coins[100]++;
    }

    for (i = 0; i < CHANGES; i++) {
        while (cents >= coins[i]) {
            result_coins[coins[i]] += 1;
            cents -= coins[i];
        }
    }

    printf("\
NOTAS:\n\
%d nota(s) de R$ 100.00\n\
%d nota(s) de R$ 50.00\n\
%d nota(s) de R$ 20.00\n\
%d nota(s) de R$ 10.00\n\
%d nota(s) de R$ 5.00\n\
%d nota(s) de R$ 2.00\n\
MOEDAS:\n\
%d moeda(s) de R$ 1.00\n\
%d moeda(s) de R$ 0.50\n\
%d moeda(s) de R$ 0.25\n\
%d moeda(s) de R$ 0.10\n\
%d moeda(s) de R$ 0.05\n\
%d moeda(s) de R$ 0.01\n\
",
        result_bills[100],
        result_bills[50],
        result_bills[20],
        result_bills[10],
        result_bills[5],
        result_bills[2],
        result_coins[100],
        result_coins[50],
        result_coins[25],
        result_coins[10],
        result_coins[5],
        result_coins[1]
    );

    return 0;
}
