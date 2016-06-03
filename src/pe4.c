/*
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */
#include <stdio.h>
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

int main()
{
    int i, j;
    int pal = 0;

    for (i = 100; i < 1000; ++i) {
        for (j = 100; j < 1000; ++j) {
            int product = i * j;
            char str[7];
            char rev[7];

            sprintf(str, "%d", product);
            strcpy(rev, str);
            strrev(rev);

            if (strcmp(str, rev) == 0 && product > pal)
                pal = product;
        }
    }

    printf("%d\n", pal);

    return 0;
}
