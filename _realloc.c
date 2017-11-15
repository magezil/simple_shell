#include "shell.h"
/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to previously allocated memory
 * @old_size: size of previously allocated memory block
 * @new_size: size of new memory block
 *
 * Return: pointer to allocated memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *cptr = ptr;
	char *reptr = NULL;
	void *newptr = NULL;
	unsigned int i, min;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0)
	{
		if (ptr != NULL)
			free(ptr);
		return (NULL);
	}

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);

	if (new_size > old_size)
		min = old_size;
	if (old_size > new_size)
		min = new_size;

	reptr = newptr;
	for (i = 0; i < min; i++)
		reptr[i] = cptr[i];

	free(ptr);
	return (newptr);
}
