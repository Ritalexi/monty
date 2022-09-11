#include "monty.h"

/**
 * handle_pint_stack_empty_error - Handles pint stack empty error.
 *
 * Return: Nothing(void).
 */
void handle_pint_stack_empty_error(void)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", global.line_count);
	fclose(global.monty_file);
	exit(EXIT_FAILURE);
}
/**
 * handle_pop_stack_empty_error - Handles pop stack empty error.
 * Return: Nothing(void).
 */
void handle_pop_stack_empty_error(void)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", global.line_count);
	fclose(global.monty_file);
	exit(EXIT_FAILURE);
}
/**
 * handle_insufficient_swap_error - Handles swap's less than two
 *                                  elements error.
 * Return: Nothing(void).
 */
void handle_insufficient_swap_error(void)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", global.line_count);
	free_stack();
	fclose(global.monty_file);
	exit(EXIT_FAILURE);
}

/**
 * handle_insufficient_add_error - Handles add's less than two
 *                                 elements error.
 * Return: Nothing(void).
 */
void handle_insufficient_add_error(void)
{
	fprintf(stderr, "L%d: can't add, stack too short\n", global.line_count);
	free_stack();
	fclose(global.monty_file);
	exit(EXIT_FAILURE);
}
/**
 * handle_insufficient_sub_error - Handles sub's less than two
 *                                 elements error.
 * Return: Nothing(void).
 */
void handle_insufficient_sub_error(void)
{
	fprintf(stderr, "L%d: can't sub, stack too short\n", global.line_count);
	free_stack();
	fclose(global.monty_file);
	exit(EXIT_FAILURE);
}
