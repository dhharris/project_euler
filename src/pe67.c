/*
 * Find the maximum total from top to bottom in triangle.txt, a 15K text file
 * containing a triangle with one-hundred rows.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#define NUM_ROWS 100

int max(int a, int b)
{
        return (a > b) ? a : b;
}

int triangle_size(int rows)
{
        return rows * (rows + 1) / 2;
}

int t_index(int row, int col)
{
        assert(row >= 0 && col >= 0 && col <= row);
        return triangle_size(row) + col;
}

int left_child(int row, int col)
{
        return t_index(row + 1, col);
}

int right_child(int row, int col)
{
        return t_index(row + 1, col + 1);
}

/*
 * Computes the max path sum in the triangle
 * Uses a dynamic programming approach to systematically reduce the size
 * of the triangle.
 *
 * In short, I iterate through every column in the second to last row,
 * then add the largest child of each element to itself.
 * Here's an illustration of the process for a simple triangle:
 *
 * 1                    1               6
 * 1 2          ->      3 5     ->
 * 1 2 3
 */
int max_path(int *triangle, int num_rows)
{
        int row, col;

        while (num_rows > 0) {
                row = num_rows - 1;
                for (col = 0; col <= row; ++col)
                        triangle[t_index(row, col)] +=
                        max(triangle[left_child(row, col)],
                        triangle[right_child(row, col)]);

                --num_rows;
        }

        return triangle[0];
}

int main()
{
        int *triangle = malloc(sizeof(int) * triangle_size(NUM_ROWS));
        FILE *fptr = fopen("data/p067_triangle.txt", "r");
        int elem;
        int num_elems = 0;

        /* Put array of numbers into memory */
        while (EOF != fscanf(fptr, "%d", &elem))
                triangle[num_elems++] = elem;

        printf("%d\n", max_path(triangle, NUM_ROWS - 1));

        free(triangle);
        fclose(fptr);

        return 0;
}
