#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
        uint64_t period = 2;
        uint64_t n = 8; /* Numbers in a spiral */
        uint64_t sum = 1;
        uint64_t m = 2;

        while (period < 1001) {
                uint64_t i;
                for (i = 1; m <= (period + 1) * (period + 1); ++i, ++m)
                        if (i % period == 0)
                                sum += m;
                period += 2;
                n *= 2;
        }

        printf("%" PRIu64 "\n", sum);

        return 0;
}
