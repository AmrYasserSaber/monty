#include "main.h"

/**
 * fDiv - Divide
 * @our_head: stack
 * @cnt: line_number
 * Return: None
 */

void fDiv(stack_t **our_head, unsigned int cnt)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", cnt);
		fclose(bus.file);
		free(bus.content);
		freeAStack(*our_head);
		exit(EXIT_FAILURE);
	}

	h = *our_head;

	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", cnt);
		fclose(bus.file);
		free(bus.content);
		freeAStack(*our_head);
		exit(EXIT_FAILURE);
	}

	aux = h->next->n / h->n;
	h->next->n = aux;


	*our_head = h->next;
	free(h);
}
