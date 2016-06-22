/*
 * How many elements would be contained in the set of reduced proper
 * fractions for d <= 1000000?
 *
 * From problem 71, I learned that one of the conditions for forming all
 * reduced proper functions is that the numerator and denominator must be
 * relatively prime. In fact, we can show that the set of all reduced proper
 * fractions will consist of just the numbers with this property.
 *
 * So if a brute force approach was used, it would look something like this:
 * (python code)
 * num_elems = 0
 *
 * for d in range(2, 1000000):
 *     for n in range(1, d):
 *         if gcd(n, d) == 1:
 *             num_elems += 1
 *
 * Realizing that this approach would take far too long, I recalled that
 * Euler's totient function, denoted Phi(n), counts the positive integers k in
 * the range 1 <= k <= n for which gcd(n, k) = 1, i.e. the number of positive
 * integers below n which are relatively prime to n.
 *
 * Therefore, I deduced that the number of elements in the set would be
 * the sum of Phi(n) where n = 2, ..., 1000000.
 */

#include <stdio.h>
#include <stdint.h>

uint64_t phi(uint64_t n)
{
        uint64_t ret = n;
        uint64_t i;

        for (i = 2; i * i <= n; ++i)
                if (n % i == 0) {
                        while (n % i == 0)
                                n /= i;
                        ret -= ret / i;
                }
        if (n > 1)
                ret -= ret / n;
        return ret;
}

int main()
{
        uint64_t sum = 0;
        uint64_t i;

        for (i = 2; i <= 1000000; ++i)
                sum += phi(i);

        printf("%lu\n", sum);

        return 0;
}
