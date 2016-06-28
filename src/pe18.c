/*
 * Find the maximum total from top to bottom of the triangle
 * (found in data/p018_triangle.txt)
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NUM_ROWS 15

int max(int a, int b)
{
        return (a > b) ? a : b;
}

int triangle_size(int rows)
{
        return rows * (rows + 1) / 2;
}

int triangle_index(int row, int col)
{
        assert(row >= 0 && col >= 0 && col <= row);
        return triangle_size(row) + col;
}

/*
 * Computes the max path sum in the triangle
 * row and col are starting coordinates. Begin from the bottom.
 */
int max_path(int *triangle, int row, int col)
{
        if (triangle_index(row, col) >= 120)
                return 0;
        return triangle[triangle_index(row, col)]
                + max(max_path(triangle, row + 1, col),
                max_path(triangle, row + 1, col + 1));
}

int main()
{
        int *triangle = malloc(sizeof(int) * triangle_size(NUM_ROWS));
        FILE *fptr = fopen("data/p018_triangle.txt", "r");
        int elem;
        int num_elems = 0;

        /* Put array of numbers into memory */
        while (EOF != fscanf(fptr, "%d", &elem))
                triangle[num_elems++] = elem;

        printf("%d\n", max_path(triangle, 0, 0));

        free(triangle);
        fclose(fptr);

        return 0;
}
