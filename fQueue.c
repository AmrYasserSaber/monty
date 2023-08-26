#include "monty.h"
/**
 * fQueue - prints the top
 * @pStack: stack pStack
 * @c: line_number
 * Return: no return
*/
void fQueue(stack_t **pStack, unsigned int c)
{
	(void)pStack;
	(void)c;
	bus.lifi = 1;
}

/**
 * addQueue - add node to the tail stack
 * @value: new_value
 * @pStack: pStack of the stack
 * Return: no return
*/
void addQueue(stack_t **pStack, int value)
{
	stack_t *new_node, *aux;

	aux = *pStack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = value;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*pStack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
