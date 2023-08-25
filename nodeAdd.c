#include "monty.h"

/**
 * nodeadd - add a new node to the head of the stack
 * @head: pointer to the head of the stack
 * @n: value to be added to the new node
 * Return: no return value
 */
void nodeadd(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}

	/* Update the previous pointer of the existing head node */
	if (aux)
		aux->prev = new_node;

	/* Set the value and pointers of the new node */
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;

	/* Update the head pointer to the new node */
	*head = new_node;
}

