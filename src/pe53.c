#include <stdio.h>
#include <stdint.h>

uint64_t min(uint64_t a, uint64_t b)
{
        return (a < b) ? a : b;
}

/*
 * Returns value of n C k
 */
uint64_t binomial_coefficient(uint64_t n, uint64_t k)
{
        uint64_t i, j;
        uint64_t C[101][101];

        /* Calculate value in a bottom up manner */
        for (i = 0; i <= n; ++i) {
                for (j = 0; j <= min(i, k); ++j) {
                        /* Base cases */
                        if (j == 0 || j == i)
                                C[i][j] = 1;

                        /* Get the answer using values from our table */
                        else
                                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
                }
        }
        return C[n][k];

}

int main()
{
        int count = 0;
        uint64_t n, r;

        for (n = 23; n < 101; ++n)
                for (r = 1; r <= n; ++r)
                        if (binomial_coefficient(n, r) > 1000000L)
                                ++count;
        printf("%d\n", count);
        return 0;
}




