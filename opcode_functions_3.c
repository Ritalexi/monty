#include "monty.h"

/**
 *  _mod - Computes the remainder of the division of the second top
 *         of the stack by the top element of the stack.
 *  @top_pointer: The address of the global variable global.top.
 *  @argument: Unused.
 *
 *  Return: Nothing(void).
 */
void _mod(stack_t **top_pointer, unsigned int argument)
{
	int modulo;

	if ((!(*top_pointer)) || (!((*top_pointer)->next)))
		handle_insufficient_mod_error();
	if ((*top_pointer)->n == 0)
		handle_topofstackis0_div_error();
	modulo = ((*top_pointer)->next->n) % ((*top_pointer)->n);
	pop(top_pointer, argument);
	(*top_pointer)->n = modulo;
}

/**
 * pchar - Prints the char at the top of the stack.
 * @top_pointer: The address of the global variable global.top.
 * @argument: Unused..
 *
 * Return: Nothing(void).
 */
void pchar(stack_t **top_pointer, unsigned int argument)
{
	int value = (*top_pointer)->n;

	UNUSED(argument);
	if (!(value >= 32 && value <= 126))
		handle_ascii_error();
	printf("%c\n", value);
}

/**
 * pstr - Prints the string starting at the top of the stack.
 * @top_pointer: The address of the global variable global.top.
 * @argument: Unused.
 *
 * Return: Nothing(void).
 */
void pstr(stack_t **top_pointer, unsigned int argument)
{
	stack_t *ptr = *top_pointer;

	UNUSED(argument);
	while (ptr && ptr->n && (ptr->n >= 1 && ptr->n <= 127))
	{
		putchar(ptr->n);
		ptr = ptr->next;
	}
	putchar('\n');
}

/**
 * rotl - Rotates the stack to the top
 * @top_pointer: The address of the global variable global.top.
 * @argument: Unused.
 *
 * Return: Nothing(void).
 */
void rotl(stack_t **top_pointer, unsigned int argument)
{
	stack_t *tmp, *ptr;

	UNUSED(argument);
	if (!(*top_pointer) || !((*top_pointer)->next))
		return;
	tmp = (*top_pointer)->next;
	ptr = *top_pointer;

	while (ptr->next)
		ptr = ptr->next;
	ptr->next = *top_pointer;
	(*top_pointer)->prev = ptr;
	(*top_pointer)->next = NULL;
	*top_pointer = tmp;
}
/**
 * rotr - Rotates the stack to the bottom
 * @top_pointer: The address of the global variable global.top.
 * @argument: Unused.
 *
 * Return: Nothing(void).
 */
void rotr(stack_t **top_pointer, unsigned int argument)
{
	stack_t *tmp, *ptr;

	UNUSED(argument);
	if (!(*top_pointer) || !((*top_pointer)->next))
		return;
	ptr = *top_pointer;
	while (ptr->next->next)
		ptr = ptr->next;
	tmp = ptr->next;
	tmp->prev = NULL;
	tmp->next = *top_pointer;
	(*top_pointer)->prev = tmp;
	ptr->next = NULL;
	*top_pointer = tmp;
}
