#include "monty.h"

/**
 * nodeadd - add
 * @our_head: pointer
 * @n: value 
 * Return: None
 */

void nodeadd(stack_t **our_head, int n)
{
	stack_t *new_node, *aux;

	aux = *our_head;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}

	if (aux)
		aux->prev = new_node;

	new_node->n = n;
	new_node->next = *our_head;
	new_node->prev = NULL;

	*our_head = new_node;

}

