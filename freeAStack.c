#include "monty.h"
/**
* freeAStack - free the stack
* @head: head of the stack
*/

void freeAStack(stack_t *head)
{
	stack_t *aux;

	aux = head;

	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
