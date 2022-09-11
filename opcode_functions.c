#include "monty.h"

/**
 * push - Pushes an element to the top(beginning) of the stack_t list.
 * @top_pointer: Address of the global variable global.top.
 * @number: Integer to be pushed to stack.
 *
 * Return: Nothing(void).
 */
void push(stack_t **top_pointer, unsigned int number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
		handle_malloc_error();
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->n = number;

	if (!(*top_pointer) && !(global.tail))
	{
		global.tail = *top_pointer = new_node;
		return;
	}
	if (global.mode == LIFO)
	{
		new_node->next = *top_pointer;
		(*top_pointer)->prev = new_node;
		*top_pointer = new_node;
	}
	else if (global.mode == FIFO)
	{
		global.tail->next = new_node;
		new_node->prev = global.tail;
		global.tail = new_node;
	}
}

/**
 * pall - Prints all the values on the stack_t list, starting from
 * the top of the stack.
 * @top_pointer: Address of the global variable global.top.
 * @argument: Unused.
 *
 * Return: Nothing(void).
 */
void pall(stack_t **top_pointer, unsigned int argument)
{
	stack_t *ptr = *top_pointer;

	UNUSED(argument);
	if (!(ptr))
		return;
	while (ptr)
	{
		printf("%u\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * pint - Prints the value at the top of the stack.
 * @top_pointer: Address of the global variable global.top.
 * @argument: Unused.
 *
 * Return: Nothing(void).
 */
void pint(stack_t **top_pointer, unsigned int argument)
{
	UNUSED(argument);
	if (!(*top_pointer))
		handle_pint_stack_empty_error();
	printf("%d\n", (*top_pointer)->n);
}

/**
 * pop - Removes the top element of the stack.
 * @top_pointer: Address of the global variable global.top.
 * @argument: Unused.
 *
 * Return: Nothing(void).
 */
void pop(stack_t **top_pointer, unsigned int argument)
{
	stack_t *tmp = NULL;

	UNUSED(argument);
	if (!(*top_pointer))
		handle_pop_stack_empty_error();
	if (!((*top_pointer)->next))
	{
		free(*top_pointer);
		*top_pointer = NULL;
		return;
	}
	tmp = (*top_pointer)->next;
	tmp->prev = NULL;
	free(*top_pointer);
	*top_pointer = tmp;
}

/**
 * swap - swaps the top of the stack with the element beneath it.
 * @top_pointer: Address of the global variable global.top.
 * @argument: Unused.
 *
 * Return: Nothing(void).
 */
void swap(stack_t **top_pointer, unsigned int argument)
{
	int tmp;

	UNUSED(argument);
	if ((!(*top_pointer)) || (!((*top_pointer)->next)))
		handle_insufficient_swap_error();
	tmp = (*top_pointer)->n;
	(*top_pointer)->n = (*top_pointer)->next->n;
	(*top_pointer)->next->n = tmp;
}
