/*
 * Using base_exp.txt, a 22K text file containing one thousand lines with a
 * base/exponent pair on each line, determine which line number has the
 * greatest numerical value.
 *
 * Since logarithms are monotonically increasing, we can determine if
 * a^b > c^d by instead checking if log(a^b) > log(c^d), which can then be
 * rewritten as b * log(a) > d * log(c).
 */
#include <stdio.h>
#include <math.h>

int main()
{
        int l;
        int maxl;
        double max;
        int base, exponent;
        FILE *fptr;

        fptr = fopen("data/p099_base_exp.txt", "r");
        max = 0;
        l = 1;

        while (fscanf(fptr, "%d,%d", &base, &exponent) != EOF) {
                int val = exponent * log(base);
                if (val > max) {
                        maxl = l;;
                        max = val;
                }
                ++l;
        }

        printf("%d\n", maxl);

        fclose(fptr);
        return 0;
}
