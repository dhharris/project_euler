/*
 * What is the smallest positive number that is evenly divisible by all
 * of the numbers from 1 to 20?
 * lcm(1, ..., 20)
 */
#include <stdio.h>

/*
 * Computes gcd(a, b) using the Euclidean Algorithm
 */
int gcd(int a, int b)
{
    int tmp;

    while (b > 0) {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int lcm(int *arr, int size)
{
    int i, ret = 1;
    for (i = 0; i < size; ++i)
        ret *= arr[i] / gcd(ret, arr[i]);

    return ret;
}

int main()
{
    int arr[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12, 13, 14, 15, 16, 17, 18, 19, 20};

    printf("%d\n", lcm(arr, 20));
    return 0;
}
