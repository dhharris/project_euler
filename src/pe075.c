/*
 * Given that L is the length of the wire, for how many values of
 * L <= 1,500,000 can exactly one integer sided right triangle be formed?
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include <assert.h>

#define NTHREADS 4
#define LIMIT 1500000
#define MAX 50000

uint64_t *perimeters;
pthread_mutex_t m;

struct range {
        uint64_t start;
        uint64_t end;
};

void *find_perimeters(void *ptr)
{
        struct range *range = (struct range*)ptr;
        uint64_t start = range->start;
        uint64_t end = range->end;
        uint64_t  r, s, t;

        for (r = start; r < end; r += 2) {
                t = r * r / 2;
                for (s = 1; s < t; ++s)
                        if (t % s == 0) {
                                uint64_t tmp = t / s;
                                uint64_t p = 3 * r + 2 * s + 2 * tmp;
                                assert(p > 0);
                                if (p <= LIMIT) {
                                        pthread_mutex_lock(&m);
                                        ++perimeters[p];
                                        pthread_mutex_unlock(&m);
                                }
                        }
        }
        free(range);
        return NULL;
}

int main()
{
        perimeters = calloc(LIMIT + 1, sizeof(uint64_t));
        pthread_t threads[NTHREADS];
        pthread_mutex_init(&m, NULL);
        uint64_t start = 2;
        uint64_t step = MAX / NTHREADS;
        uint64_t end = start + step;
        int i, count = 0;

        for (i = 0; i < NTHREADS; ++i) {
                struct range *r = malloc(sizeof(struct range));
                r->start = start;
                r->end = end;

                pthread_create(&threads[i], NULL, find_perimeters, (void*)r);
                start += step;
                end += step;
        }

        for (i = 0; i < NTHREADS; ++i)
                pthread_join(threads[i], NULL);

        int max = 0;
        for (i = 0; i <= LIMIT; ++i) {
                if (perimeters[i] && i > max)
                        max = i;
                if (perimeters[i] == 1)
                        ++count;
        }

        printf("%d (max_p = %d)\n", count, max);

        free(perimeters);
        pthread_mutex_destroy(&m);

        return 0;
}

