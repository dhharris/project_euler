/*
 * Find the first four consecutive integers to have four distinct prime
 * factors. What is the first of these numbers?
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define LIMIT 1000000

/*
 * Uses the Sieve of Erosthenes to generate prime numbers
 *
 * Returns boolean valued array for all numbers from 0 to limit.
 * If the value of primes[i] is 1, then the number is prime
 *
 * Make sure to free the primes array after using
 */
int *generate_primes(int limit)
{
        int i, j;
        int *primes = malloc(limit * sizeof(int));

        primes[0] = primes[1] = 0;
        for (i = 2; i < limit; ++i)
                primes[i] = 1;

        for (i = 2; i < limit; ++i)
                if (primes[i])
                        for (j = i; i * j < limit; ++j)
                                primes[i * j] = 0;
        return primes;
}

/*
 * Finds the number of prime factors that exist for a given number
 */
int num_factors(int *primes, int n)
{
        int num_factors = 1;
        int i;

        /* Iterate over all the prime numbers up to sqrt(n) */
        for (i = 0; i * i < n; ++i) {
                if (!primes[i])
                        continue;

                /* If we found a prime factor, divide it out */
                if (n % i == 0) {
                        ++num_factors;
                        while (n % i == 0)
                                n /= i;
                }
        }
        return num_factors;
}

int main()
{
        int *primes = generate_primes((size_t)sqrt(LIMIT));
        int i;

        for (i = 647; i < LIMIT; ++i) {
                if (num_factors(primes, i) == 4 &&
                num_factors(primes, i + 1) == 4 &&
                num_factors(primes, i + 2) == 4 &&
                num_factors(primes, i + 3) == 4) {
                        printf("%d\n", i);
                        break;
                }
        }

        free(primes);
        return 0;
}
