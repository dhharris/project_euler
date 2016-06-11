/*
 * What is the largest prime factor of the number 600851475143 ?
 */
#include <stdio.h>
#include <stdint.h>

int main()
{
        uint64_t num = 600851475143;
        uint64_t divisor = 2;

        while (num > 1) {
                if (num % divisor == 0) {
                        num /= divisor;
                        --divisor;
                }
                ++divisor;
        }

        printf("%llu\n", divisor);

        return 0;
}
