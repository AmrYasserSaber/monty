#include "monty.h"
/**
  *fRotr- rotates the stack to the bottom
  *@pStack: stack pStack
  *@c: line_number
  *Return: no return
 */
void fRotr(stack_t **pStack, __attribute__((unused)) unsigned int c)
{
	stack_t *copy;

	copy = *pStack;
	if (*pStack == NULL || (*pStack)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *pStack;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*pStack)->prev = copy;
	(*pStack) = copy;
}
