#include <stdio.h>

int main() {
    int all_solved_at_least_one;
    int every_solved_by_at_least_one;
    int nobody_solved_all;
    int not_solved_by_everyone;
    int problems[128];
    int total;
    int sol;
    int i;
    int j;
    int m;
    int n;

    while (scanf("%d %d", &n, &m) != EOF) {
        if (n == 0) {
            break;
        }
        for (i = 0; i < m; i++) {
            problems[i] = 0;
        }

        all_solved_at_least_one = 1;
        nobody_solved_all = 1;
        for (i = 0; i < n; i++) {
            total = 0;
            for (j = 0; j < m; j++) {
                scanf("%d", &sol);
                if (sol == 1) {
                    problems[j]++;
                    total++;
                }
            }
            if (total == 0) {
                all_solved_at_least_one = 0;
            } else if (total == m) {
                nobody_solved_all = 0;
            }
        }

        every_solved_by_at_least_one = 1;
        not_solved_by_everyone = 1;
        for (i = 0; i < m; i++) {
            if (problems[i] == 0) {
                every_solved_by_at_least_one = 0;
            } else if (problems[i] == n) {
                not_solved_by_everyone = 0;
            }
        }

        printf("%d\n",
            nobody_solved_all +
            every_solved_by_at_least_one +
            not_solved_by_everyone +
            all_solved_at_least_one
        );
    }

    return 0;
}
