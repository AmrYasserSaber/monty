#include "monty.h"
/**
 * fPstr - prints the string starting at the top of the stack,
 * followed by a new
 * @pStack: stack pStack
 * @c: line_number
 * Return: no return
*/
void fPstr(stack_t **pStack, unsigned int c)
{
	stack_t *head;
	(void)c;

	head = *pStack;
	while (head)
	{
		if (head->n > 127 || head->n <= 0)
		{
			break;
		}
		printf("%c", head->n);
		head = head->next;
	}
	printf("\n");
}
