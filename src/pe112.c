/*
 * Find the least number for which the proportion of bouncy numbers is exactly
 * 99%.
 */
#include <stdio.h>

#define TOL 0.99

int is_bouncy(int n)
{
        int inc = 0; /* Flags to tell if we are inc or dec */
        int dec = 0;
        int curr;
        int prev = n % 10; /* Starts as first digit */

        for (n /= 10; n; n /= 10) {
                if (inc && dec)
                        return 1;

                curr = n % 10;

                if (curr > prev)
                        inc = 1;
                else if (curr < prev)
                        dec = 1;

                prev = curr;
        }
        return inc && dec;
}

int main()
{
        int i;
        int count = 0;
        double ratio = 0;

        for (i = 1; ratio < TOL; ++i) {
                if (is_bouncy(i))
                        ++count;
                ratio = count / (double)i;
        }

        printf("%d\n", i - 1);

        return 0;
}
