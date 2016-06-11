/*
 * Find the sum of all the primes below two million.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <pthread.h>

#define MAX 2000000
#define NUM_THREADS 4

struct range {
        uint64_t start, end;
};

void *sum_primes(void *ptr)
{
        struct range *r = (struct range*)ptr;
        uint64_t start = r->start;
        uint64_t end = r->end;
        free(r);

        uint64_t i, j;
        uint64_t sum = 0;

        for (i = start; i < end; ++i) {
                int flag = 0;

                if (i == 2) {
                        sum += 2;
                        continue;
                }

                if (i % 2 == 0)
                        continue;

                uint64_t sqrt_i = sqrt(i);
                for (j = 3; j <= sqrt_i; j += 2) {
                        if (i % j == 0) {
                                flag = 1;
                                break;
                        }
                }
                if (!flag && i >= 2)
                        sum += i;
        }
        return (void*)(uintptr_t)sum;
}

int main()
{
        uint64_t sum = 0;
        pthread_t threads[NUM_THREADS];
        int i;
        uint64_t start, end;
        uint64_t step = MAX / NUM_THREADS;

        start = 0;
        end = step;

        for (i = 0; i < NUM_THREADS; ++i) {
                struct range *r = malloc(sizeof(struct range));
                r->start = start;
                r->end = end;

                pthread_create(&threads[i], NULL, sum_primes, (void*)r);
                start += step;
                end += step;
        }

        for (i = 0; i < NUM_THREADS; ++i) {
                void *ret;
                pthread_join(threads[i], &ret);
                sum += (uintptr_t)ret;
        }

        printf("%llu\n", sum);


        return 0;
}
