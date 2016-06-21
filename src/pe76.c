/*
 * How many different ways can one hundred be written as a sum of at least two
 * positive integers?
 */

int cache[101][101];

#include <stdio.h>

/*
 * Returns the number of partitions of n using only positive integers
 * that are _less_than_or_equal_to_ m.
 *
 * This function is memoized using a global cache to avoid repeat calculations
 */
int p(int n, int m)
{
        if (n < 0)
                return 0;
        if (n == 0 || n == 1)
                return 1;
        if (m > n)
                return p(n, n);

        int i, sum = 0;

        for (i = 1; i <= m; ++i) {
                if (!cache[n - i][i])
                        cache[n - i][i] = p(n - i, i);
                sum += cache[n - i][i];
        }
        return sum;
}

/*
 * Calculates the partition of n, or the number of ways n can be written
 * as a sum of at least two positive integers.
 */
int partition(int n)
{
        return p(n, n - 1);
}

int main()
{
        printf("%d\n", partition(100));
        return 0;
}
