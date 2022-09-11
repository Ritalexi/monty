#include "monty.h"

/**
 * stack - sets the format of the data to a stack (LIFO)
 * @top_pointer: Unused.
 * @number: Unused.
 *
 * Return: Nothing(void).
 */
void stack(stack_t **top_pointer, unsigned int number)
{
	UNUSED(number);
	UNUSED(top_pointer);
	global.mode = LIFO;
}

/**
 * queue - sets the format of the data to a queue (FIFO)
 * queue - sets the format of the data to a queue (FIFO)
 * @number: Unused
 *
 * Return: Nothing(void).
 */
void queue(stack_t **top_pointer, unsigned int number)
{
	UNUSED(number);
	UNUSED(top_pointer);
	global.mode = FIFO;
}
