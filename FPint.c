#include "monty.h"
/**
 * fPint - prints the top
 * @h: stack head
 * @c: line_number
 * Return: no return
*/
void fPint(stack_t **h, unsigned int c)
{
	if (*h == NULL)
	{
		fprintf(stderr, "L%u: stack empty\n", c);
		fclose(bus.file);
		free(bus.content);
		freeAStack(*h);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*h)->n);
}
