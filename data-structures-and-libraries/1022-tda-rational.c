#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    char op;
    int den;
    int num;
    int d1;
    int d2;
    int n1;
    int n2;
    int n;
    int x;

    scanf("%d", &n);
    while (n > 0) {
        scanf("%d / %d %c %d / %d", &n1, &d1, &op, &n2, &d2);
        switch (op) {
            case '+':
                num = (n1 * d2 + n2 * d1);
                den = (d1 * d2);
                break;
            case '-':
                num = (n1 * d2 - n2 * d1);
                den = (d1 * d2);
                break;
            case '*':
                num = (n1 * n2);
                den = (d1 * d2);
                break;
            case '/':
                num = n1 * d2;
                den = n2 * d1;
                break;
        }
        x = abs(gcd(num, den));
        printf("%d/%d = %d/%d\n", num, den, num / x, den / x);
        n--;
    }

    return 0;
}
