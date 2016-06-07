/*
 * Find the product of the coefficients, a and b, for the quadratic expression
 * that produces the maximum number of primes for consecutive values of n,
 * starting with n = 0.
 */
#include <stdio.h>

int is_prime(int n)
{
        int i;

        /* Base case */
        if (n == 2)
                return 1;
        if (n < 0 || n % 2 == 0)
                return 0;

        for (i = 3; i * i <= n; i += 2)
                if (n % i == 0)
                        return 0;

        return 1;
}

int nprimes(int a, int b)
{
        int n;

        for (n = 0; is_prime(n * n + a * n + b); ++n);
        return n;
}

int main()
{
        int max = 0;
        int prod = 0;
        int a, b, n;

        /* a must be odd, b must be odd and positive */
        for (a = -999; a < 1000; a += 2)
                for (b = 1; b < 1000; b += 2)
                        if ((n = nprimes(a, b)) > max) {
                                max = n;
                                prod = a * b;
                        }

        printf("%d\n", prod);

        return 0;
}
