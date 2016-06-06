#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_permutation(int *arr, int len)
{
    int i;
    for (i = 0; i < len; ++i)
        printf("%d", arr[i]);
    puts("");
}

int next_permutation(int *arr, int len)
{
    int i, j;
    for (i = len - 1; i > 0 && arr[i - 1] >= arr[i]; --i);
    if (i <= 0)
        return -1; /* Error */

    for (j = len - 1; arr[j] <= arr[i - 1]; --j);

    swap(&arr[i - 1], &arr[j]);

    for (j = len - 1; i < j; ++i, --j)
        swap(&arr[i], &arr[j]);

    return 0;
}

int main()
{
    int i;
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (i = 1; i < 1000000 && next_permutation(arr, 10) != -1; ++i);
    print_permutation(arr, 10);
    return 0;
}
