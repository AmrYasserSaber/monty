#include "monty.h"

/**
 * add_top_two - adds the top two elements of the stack
 * @head: pointer to the head of the stack
 * @counter: the line number in the bytecode file
 * Return: no return value
 */
void add_top_two(stack_t **head, unsigned int counter)
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

	/* Check if there are at least two elements to add */
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		freeAStack(*head);
		exit(EXIT_FAILURE);
	}

	/* Reset 'h' to the head of the stack */
	h = *head;

	/* Calculate the sum of the top two elements */
	aux = h->n + h->next->n;

	/* Update the second element's value with the sum */
	h->next->n = aux;

	/* Remove the first element (top of the stack) */
	*head = h->next;
	free(h);
}

