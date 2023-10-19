#include "monty.h"

/**
 * malloc_error - this print malloc error
 * Return: void
 */

void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
