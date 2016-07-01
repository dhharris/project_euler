#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

char *strrev(char *str)
{
        int i = strlen(str)-1, j=0;
        char ch;

        while(i > j) {
                ch = str[i];
                str[i]= str[j];
                str[j] = ch;
                i--;
                j++;
        }

        return str;
}

uint64_t numrev(uint64_t n)
{
        char num[30];
        sprintf(num, "%" PRIu64, n);
        strrev(num);
        return strtoull(num, NULL, 10);
}

int is_pal(uint64_t n)
{
        char num[30];
        char numr[30];

        sprintf(num, "%" PRIu64, n);
        strcpy(numr, num);
        strrev(numr);
        return strcmp(num, numr) == 0;
}

int is_lychrel(uint64_t n)
{
        int i;

        for (i = 0; i < 50; ++i) {
                n += numrev(n);
                if (is_pal(n))
                        return 0;
        }
        return 1;
}

int main()
{
        int count = 0;
        uint64_t i;

        for (i = 1; i < 10000; ++i)
                if (is_lychrel(i))
                        ++count;

        printf("%d\n", count);
        return 0;
}
