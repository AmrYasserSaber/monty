#include "monty.h"

/**
 * fDiv - divides the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void fDiv(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;

	/* Count the number of elements in the stack */
	while (h)
	{
		h = h->next;
		len++;
	}

	/* Check if there are at least two elements to divide */
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		freeAStack(*head);
		exit(EXIT_FAILURE);
	}

	/* Reset 'h' to the head of the stack */
	h = *head;

	/* Check for division by zero */
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		freeAStack(*head);
		exit(EXIT_FAILURE);
	}

	/* Perform the division and update the second element's value */
	aux = h->next->n / h->n;
	h->next->n = aux;

	/* Remove the first element (top of the stack) */
	*head = h->next;
	free(h);
}
