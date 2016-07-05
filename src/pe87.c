/*
 * How many numbers below fifty million can be expressed as the sum of a prime
 * square, prime cube, and prime fourth power?
 */

#include <stdio.h>
#include <stdlib.h>

#define NPRIMES 7100
#define MAX 50000000

int is_prime(int n)
{
        if (n < 2)
                return 0;
        if (n == 2)
                return 1;
        if (n % 2 == 0)
                return 0;
        int i;
        for (i = 3; i * i <= n; i += 2)
                if (n % i == 0)
                        return 0;
        return 1;

}

/*
 * Given an array of length n, caches the results of is_prime
 * for i = 0, ..., len - 1
 */
void generate_parray(int *parray, int len)
{
        int i;
        for (i = 2; i < len; ++i)
                parray[i] = is_prime(i);
}

/*
 * Returns the triple described in the problem
 */
int sum(int a, int b, int c)
{
        return a * a + b * b * b + c * c * c * c;
}

int main()
{
        int *primes = calloc(NPRIMES, sizeof(int));
        int *triples = calloc(MAX, sizeof(int));
        int a, b, c;
        int i;
        int count = 0;

        /* Cache prime numbers so we don't have to compute repeatedly */
        generate_parray(primes, NPRIMES);

        /* Iterate through every possible triple. We can bound this using
         * roots. i.e. given the condition a^2 + b^3 + c^4 < 50000000, we know
         * that a, b, c are going to be bounded by the nth root of 50000000.
         * So a < 7072, b < 369 and c < 85.
         */
        for (a = 2; a < 7072; ++a)
                for (b = 2; b < 369; ++b)
                        for (c = 2; c < 85; ++c) {
                                /* Check that conditions are met */
                                if (!(primes[a] && primes[b] && primes[c]))
                                        continue;
                                int s = sum(a, b, c);
                                if (s < MAX)
                                        triples[s] = 1;
                        }

        for (i = 0; i < MAX; ++i)
                count += triples[i];

        printf("%d\n", count);
        free(primes);
        free(triples);

        return 0;
}
