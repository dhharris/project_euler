/*
 * Evaluate the sum of all the amicable numbers under 10000.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int d(int n)
{
        int i, sum = 1;
        for (i = 2; i * i <= n; ++i)
                sum += n % i ? 0 : (i * i == n ? i : i + n / i);
        return sum;
}

int main()
{
        int sum = 0;
        int a;

        for (a = 1; a < 10000; ++a) {
                int b = d(a);
                if (a != b && a == d(b))
                        sum += a;
        }
        printf("%d\n", sum);

        return 0;
}
