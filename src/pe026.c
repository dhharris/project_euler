/*
 * Find the value of d < 1000 for which 1 / d contains the longest recurring
 * cycle in its decimal fraction part.
 */
#include <stdio.h>
#include <stdint.h>

/*
 * Performs long division for the expression n / d while counting number of
 * iterations until either the remainder is zero or we are back with the
 * expression we started with.
 *
 * Returns the number of iterations performed.
 */
int ldivide(int n, int d)
{
        int first = n;
        int count = 0;

        while (1) {
                while (n / d == 0)
                        n *= 10;

                n %= d;
                ++count;

                if (n == 0)
                        return 0;
                if (n == first || n == 10 || n == 100 || n == 1000)
                        return count;
        }
}

int main()
{
        int d;
        int max, maxd;

        max = 0;
        maxd = 0;

        printf("%d\n", ldivide(1, 443));

        for (d = 2; d < 1000; ++d) {
                int len = ldivide(1, d);
                if (len > max) {
                        max = len;
                        maxd = d;
                }
        }

        printf("%d\n", maxd);

        return 0;
}
