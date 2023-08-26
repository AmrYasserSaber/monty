#include "monty.h"

/**
 * add_top_two - adding
 * @our_head: our pointer
 * @cnt: counter
 * Return: None
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

