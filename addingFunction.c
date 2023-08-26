#include "main.h"

/**
 * add_top_two - adds the top two elements of the stack
 * @our_head: pointer to the our_head of the stack
 * @cnt: the line number in the bytecode file
 * Return: no return value
 * 
 */


void add_top_two(stack_t **our_head, unsigned int cnt)
{
	stack_t *h;
	int len = 0, aux;

	h = *our_head;

	while (h)
	{
		h = h->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", cnt);
		fclose(bus.file);
		free(bus.content);
		freeAStack(*our_head);
		exit(EXIT_FAILURE);

	}

	h = *our_head;

	aux = h->n + h->next->n;

	h->next->n = aux;

	*our_head = h->next;

	free(h);
}

