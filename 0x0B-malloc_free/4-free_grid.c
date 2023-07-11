#include <stdlib.h>
#include "main.h"

/**
 * free_grid - Frees a 2D grid previously created by alloc_grid.
 * @grid: Pointer to the 2D grid.
 * @height: The height of the grid.
 */
void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL || height <= 0)
		return;

	/* Free the memory for each row */
	for (i = 0; i < height; i++)
		free(grid[i]);

	/* Free the memory for the row pointers */
	free(grid);
}

