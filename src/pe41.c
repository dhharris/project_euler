/*
 * What is the largest n-digit pandigital prime?
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int is_pandigital(uint64_t n)
{
        int ndigits = 0;
        int digits[10] = {0};
        int i;

        for (; n; n /= 10) {
                if (n % 10 == 0)
                        return 0;
                ++digits[n % 10];
                ++ndigits;
        }

        for (i = 1; i <= ndigits; ++i)
                if (digits[i] != 1)
                        return 0;
        return 1;
}

int is_prime(uint64_t n)
{
        if (n == 2)
                return 1;
        if (n % 2 == 0)
                return 0;

        uint64_t i;
        for (i = 3; i * i <= n; i += 2)
                if (n % i == 0)
                        return 0;
        return 1;
}

int main()
{
        uint64_t n;

        for (n = 7654321; n >= 1234567; n -= 2)
                if (is_pandigital(n) && is_prime(n))
                        break;

        printf("%llu\n", n);

        return 0;
}
