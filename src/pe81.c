/*
 * Find the minimal path sum, in matrix.txt, a 31K text file containing a
 * 80 by 80 matrix, from the top left to the bottom right by only moving right
 * and down.
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NUM_COLS 80
#define NUM_ROWS 80
#define GRID_SIZE NUM_ROWS * NUM_COLS

int min(int a, int b)
{
        /* -1 is an error value and allows us to detect out of bounds */
        if (b == -1 && a == -1)
                return 0;
        if (a == -1)
                return b;
        if (b == -1)
                return a;
        return (a < b) ? a : b;
}

int valid_index(int row, int col)
{
        return row >= 0 && col >= 0 && row < NUM_ROWS && col < NUM_COLS;
}

int gindex(int row, int col)
{
        assert(valid_index(row, col));
        return row * NUM_COLS + col;
}

int right_cell(int *grid, int row, int col)
{
        if (!valid_index(row, col + 1))
                return -1;
        return grid[gindex(row, col + 1)];
}

int lower_cell(int *grid, int row, int col)
{
        if (!valid_index(row + 1, col))
                return -1;
        return grid[gindex(row + 1, col)];
}

int min_path(int *grid)
{
        int row, col;
        row = NUM_ROWS - 1;

        while (row >= 0) {
                for (col = NUM_COLS - 1; col >= 0; --col)
                        grid[gindex(row, col)] +=
                                min(right_cell(grid, row, col),
                                lower_cell(grid, row, col));

                --row;
        }
        return grid[0];
}

int main()
{
        int *grid = malloc(sizeof(int) * GRID_SIZE);
        FILE *fptr = fopen("data/p081_matrix.txt", "r");
        int elem;
        int num_elems = 0;

        /* Put array of numbers into memory */
        while (fscanf(fptr, "%d,", &elem) > 0)
                grid[num_elems++] = elem;

        printf("%d\n", min_path(grid));

        free(grid);
        fclose(fptr);

        return 0;
}
