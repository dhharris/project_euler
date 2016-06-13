/*
 * Found the key by generating all valid results for all three letter key
 * combinations, then manually scanning output (../data/pe59_output.txt)
 * to find the correct key
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>

#define FILENAME "data/p059_cipher.txt"

void xor_encrypt(char *key, int *data, size_t nbytes)
{
        int i;
        int keylen = strlen(key);
        for (i = 0; i < (int)nbytes; ++i)
                data[i] = data[i]^(int)key[i % keylen];
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

/*
 * Perform a deep copy of the data array
 */
int *copy_data(int *data, size_t nbytes)
{
        int i;
        int *cpy = malloc(sizeof(int) * nbytes);

        for (i = 0; i < (int)nbytes; ++i)
                cpy[i] = data[i];

        return cpy;
}

/*
 * Print results
 *
 * Do not print any results which yield unprintable characters
 */
void print_results(char *key, int *data, size_t nbytes)
{
        int i;
        char *buf = malloc(nbytes);
        size_t bufsize = 0;

        for (i = 0; i < (int)nbytes; ++i) {
                if (isprint(data[i]))
                        buf[bufsize++] = data[i];
                else {
                        free(buf);
                        return;
                }
        }

        printf("Result for key %s: ", key);

        for (i = 0; i < (int)bufsize; ++i)
                putchar(buf[i]);
        putchar('\n');

        free(buf);
}

int main()
{
        FILE *fptr = fopen(FILENAME, "r");
        char *lineptr = NULL;
        char key[] = "god";
        size_t n = 0;
        size_t nbytes = 0;
        ssize_t c;
        off_t file_size;
        int *data;
        int sum = 0;
        int i;

        if ((file_size = fsize(FILENAME)) == -1) {
                perror("fsize()");
                return 1;
        }

        data = malloc(sizeof(int) * file_size);

        if (!data) {
                perror("malloc()");
                return 1;
        }

        while ((c = getdelim(&lineptr, &n, ',', fptr) != -1))
                data[nbytes++] = atoi(lineptr);


        xor_encrypt(key, data, nbytes);
        for (i = 0; i < (int)nbytes; ++i) {
                putchar(data[i]);
                sum += data[i];
        }
        putchar('\n');
        printf("%d\n", sum);

        free(data);
        free(lineptr);
        fclose(fptr);

        return 0;
}
