#include <stdio.h>
#include <math.h>

int main()
{
        int sum = 0;
        int i;

        /* 2, 3, ..., 9^5 * 6 */
        for (i = 2; i <= 354294; ++i) {
                int tmp;
                int digit_sum = 0;
                for (tmp = i; tmp; tmp /= 10)
                        digit_sum += pow(tmp % 10, 5);
                if (i == digit_sum)
                        sum += i;
        }
        printf("%d\n", sum);

        return 0;
}
