#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc(const void *a, const void *b)
{
        return *(char*)a - *(char*)b;
}

int digitcmp(int a, int b)
{
        char astr[10];
        char bstr[10];
        sprintf(astr, "%d", a);
        sprintf(bstr, "%d", b);
        qsort(astr, strlen(astr), 1, cmpfunc);
        qsort(bstr, strlen(bstr), 1, cmpfunc);
        return strcmp(astr, bstr) == 0;
}

int main()
{
        int i = 1;

        while (1) {
                if (digitcmp(i, 2 * i) && digitcmp(i, 3 * i)
                && digitcmp(i, 4 * i) && digitcmp(i, 5 * i)
                && digitcmp(i, 6 * i))
                        break;
                ++i;
        }
        printf("%d\n", i);
        return 0;
}
