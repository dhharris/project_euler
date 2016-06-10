#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define FILENAME "data/p059_cipher.txt"

void xor_encrypt(char *key, char *str, size_t nbytes)
{
        int i;
        int keylen = strlen(key);
        for (i = 0; i < (int)nbytes; ++i)
                str[i] = str[i]^key[i % keylen];
}

/*
 * Increment the letters in 'str'. Returns 1 if the increment is successful.
 * Returns 0 if all the letters in the string are 'z'
 *
 * For example:
 *      If str == "howdy", str will be changed to "howdz"
 *              and the function will return 1.
 *      If str == "jazz", str will be changed to "jbaa"
 *              and the function will return 1.
 *      If str == "zzzzzz", str will be unchanged
 *              and the function will return 0.
 *
 * 'str' must contain only lowercase letters, and it will contain only
 * lowercase letters when the function returns.
 */
int increment_string(char *str)
{
        char *p = str + strlen(str) - 1;

        /* Find the last character after the prefix that is not a z */
        while(p >= str && *p == 'z')
                --p;

        /* If we found one, increment it */
        if (p >= str) {
                /* Increment this character and move to the next one */
                (*p++)++;

                /* And set all the remaining characters to 'a' */
                while (*p)
                        *p++ = 'a';

                return 1;
        }
        else
                /* Reached the end so return 0 */
                return 0;
}

off_t fsize(const char *filename)
{
        struct stat st;

        if (stat(filename, &st) == 0)
                return st.st_size;
        return -1;
}

int main()
{
        FILE *fptr = fopen(FILENAME, "r");
        char *lineptr = NULL;
        size_t n = 0;
        size_t nbytes = 0;
        ssize_t c;
        off_t file_size;
        char *data;
        int i;

        if ((file_size = fsize(FILENAME)) == -1) {
                perror("fsize()");
                return 1;
        }

        data = malloc(file_size + 1);

        if (!data) {
                perror("malloc()");
                return 1;
        }

        while ((c = getdelim(&lineptr, &n, ',', fptr) != -1))
                data[nbytes++] = atoi(lineptr);

        for (i = 0; i < (int)nbytes; ++i)
                printf("%d\n", data[i]);
        /* Add null byte to data */
        data[nbytes] = '\0';
        printf("%s",data);

        return 0;
}
