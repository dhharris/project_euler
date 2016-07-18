/*
 * Find the value of d < 1000 for which 1 / d contains the longest recurring
 * cycle in its decimal fraction part.
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * Performs long division for the expression n / d while counting number of
 * iterations until either the remainder is zero or we are back with the
 * expression we started with.
 *
 * Every time we need to 'carry a zero', i.e. multiply by ten, we increment
 * count.
 *
 * Returns the period of the repeating decimal for n / d.
 */
int ldivide(int n, int d)
{
        int first = n;
        int count = 0;

        while (1) {
                while (n / d == 0) {
                        n *= 10;
                        ++count;
                }

                n %= d;


                if (n == 0)
                        return 0;
                if (n == first)
                        return count;

        }
}

int is_prime(int n)
{
        if (n == 2)
                return 1;
        if (n % 2 == 0)
                return 0;

        int k;

        for (k = 3; k * k <= n; ++k)
                if (n % k == 0)
                        return 0;
        return 1;
}

int main()
{
        int i, d, max;
        max = 0;

        for (i = 2; i < 1000; ++i) {
                /* Iterate over only primes since composite numbers have the
                 * same period length as their prime factors
                 */
                if (!is_prime(i))
                        continue;

                int period = ldivide(1, i);
                if (period > max) {
                        max = period;
                        d = i;
                }
        }

        printf("%d\n", d);

        return 0;
}
