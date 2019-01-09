#include <stdio.h>
#include <string.h>

#define LIST_SIZE 1000000

int main() {
    unsigned long long factors[2];
    unsigned long long n;
    unsigned long long p;
    unsigned long long q;
    unsigned long long r;
    char isprime[LIST_SIZE];
    int primes[LIST_SIZE] = {0};
    int spf[LIST_SIZE] = {0};
    int i;
    int j;
    int k;
    int m;

    memset(isprime, 1, LIST_SIZE);
    isprime[0] = 0;
    isprime[1] = 0;

    k = 0;
    for (i = 2; i < LIST_SIZE; i++) {
        if (isprime[i] == 1) {
            spf[i] = i;
            primes[k] = i;
            k++;
        }
        j = 0;
        while ((j < k) && ((i * primes[j]) < LIST_SIZE) && (primes[j] < spf[i])) {
            m = i * primes[j];
            isprime[m] = 0;
            spf[m] = primes[j];
            j++;
        }
    }

    while(scanf("%llu", &n)) {
        if (n == 0) {
            break;
        }
        j = 0;
        for (i = 0; i < k; i++) {
            if ((n % primes[i]) == 0) {
                factors[j] = primes[i];
                j++;
                if (j == 2) {
                    break;
                }
            }
        }
        p = factors[0];
        q = factors[1];
        r = n / p / q;
        printf("%llu = %llu x %llu x %llu\n", n, p, q, r);
    }

    return 0;
}
