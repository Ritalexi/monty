#include "monty.h"

/**
 * free_stack - Frees the stack_t list.
 *
 * Return: Nothing
 */
void free_stack(void)
{
	stack_t *tmp = global.top;

	while (global.top)
	{
		tmp = global.top->next;
		free(global.top);
		global.top = tmp;
	}
}
