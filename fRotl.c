#include "monty.h"
/**
  *fRotl- rotates the stack to the top
  *@pStack: stack pStack
  *@c: line_number
  *Return: no return
 */
void fRotl(stack_t **pStack, __attribute__((unused)) unsigned int c)
{
	stack_t *tmp = *pStack, *aux;

	if (*pStack == NULL || (*pStack)->next == NULL)
	{
		return;
	}
	aux = (*pStack)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *pStack;
	(*pStack)->next = NULL;
	(*pStack)->prev = tmp;
	(*pStack) = aux;
}
