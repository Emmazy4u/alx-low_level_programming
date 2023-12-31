#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - nested loop to make grid
 * @width: width input
 * @height: height input
 * Return: pointer to 2 dim. array
 */
int **alloc_grid(int width, int height)
{
	int **buff, i, j, k;

	if (width <= 0 || height <= 0)
		return (NULL);
	buff = (int **) malloc(sizeof(int *) * height);
	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}
	for (i = 0; i < height; i++)
	{
		buff[i] = (int *) malloc(sizeof(int) * width);
		if (buff[i] == NULL)
		{
			for (k = 0; k <= i; k++)
			{
				free(buff[k]);
				free(buff);
				return (NULL);
			}
		}
		for (j = 0; j < width; j++)
			buff[i][j] = 0;
	}
	return (buff);
}
