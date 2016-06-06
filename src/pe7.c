/*
 * What is the 10 001st prime number?
 */

#include <stdio.h>
#include <math.h>

int find_nth_prime(int n)
{
    int count = 0;
    int i, j;
    int p = -1;

    for(i = 0; count < n; ++i) {
        int flag = 0;

        /* Only check if odd numbers are prime.
         * base case is i = 2
         */
        if (i == 2) {
            ++count;
            continue;
        }
        if (i % 2 == 0)
            continue;

        /* Check if our number is divisible by any odd
         * number up to its sqrt
         */
        int sqrt_i = sqrt(i);
        for (j = 3; j <= sqrt_i; j += 2) {
            if (i % j == 0) {
                flag = 1;
                break;
            }
        }
        if (!flag && i >= 2) {
            ++count;
            p = i;
        }
    }
    return p;
}

int main()
{
    printf("%d\n", find_nth_prime(10001));        
    return 0;
}
