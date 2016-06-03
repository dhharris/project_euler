/*
 * By considering the terms in the Fibonacci sequence whose values do not exceed four million,
 * find the sum of the even-valued terms.
 */
#include <stdio.h>
#include <stdint.h>

int main()
{
    uint64_t sum = 2;
    uint64_t a = 1, b = 2;
    uint64_t f;

    for (f = 3; f < 4000000; f = a + b) {
        if (f % 2 == 0)
            sum += f;
        a = b;
        b = f;
    }

    printf("%lu\n", sum);

    return 0;
}
