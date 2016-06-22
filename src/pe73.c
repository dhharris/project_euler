/*
 * How many fractions lie between 1/3 and 1/2 in the sorted set of reduced
 * proper fractions for d <= 12000?
 */

#include <stdio.h>

int gcd(int a, int b)
{
        int tmp;

        while (b) {
                tmp = b;
                b = a % b;
                a = tmp;
        }

        return a;
}

int main()
{
        int n, d, count = 0;

        for (d = 5; d <= 12000; ++d)
                for (n = d / 3; n < d / 2; ++n)
                        if (gcd(n, d) == 1)
                                ++count;

        printf("%d\n", count);

        return 0;
}
