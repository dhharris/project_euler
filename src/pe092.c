/*
 * A number chain is created by continuously adding the square of the digits
 * in a number to form a new number until it has been seen before.
 *
 * For example,
 *      44 -> 32 -> 13 -> 10 -> 1 -> 1
 *      85 -> 89 -> 145 -> 42 -> 20 -> 4 -> 16 -> 37 -> 58 -> 89
 *
 * Therefore any chain that arrives at 1 or 89 will become stuck in an endless
 * loop. What is most amazing is that EVERY starting number will eventually
 * arrive at 1 or 89.
 *
 * How many starting numbers below ten million will arrive at 89?
 */

#include <stdio.h>

int chain(int n)
{
        while (n != 1 && n != 89) {
                int sum = 0;
                while (n) {
                        int digit = n % 10;
                        sum += digit * digit;
                        n /= 10;
                }
                n = sum;
        }
        return n;
}

int main()
{
        int i;
        int sum = 0;

        for (i = 1; i < 10000000; ++i)
                if (chain(i) == 89)
                        ++sum;

        printf("%d\n", sum);

        return 0;
}
