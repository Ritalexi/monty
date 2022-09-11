#include "monty.h"

/**
 * handle_insufficient_div_error - Handles div's less than two
 *                                 elements error.
 * Return: Nothing(void).
 */
void handle_insufficient_div_error(void)
{
	fprintf(stderr, "L%d: can't div, stack too short\n", global.line_count);
	free_stack();
	fclose(global.monty_file);
	exit(EXIT_FAILURE);
}

/**
 * handle_topofstackis0_div_error - Handles error that comes about when
 *                                  top of stack is 0 to avoid division by 0.
 * 
 * Return: Nothing(void).
 */
void handle_topofstackis0_div_error(void)
{
	fprintf(stderr, "L%d: division by zero\n", global.line_count);
	free_stack();
	fclose(global.monty_file);
	exit(EXIT_FAILURE);
}

/**
 * handle_insufficient_mul_error - Handles mul's less than two
 *                                 elements error.
 * Return: Nothing(void).
 */
void handle_insufficient_mul_error(void)
{
	fprintf(stderr, "L%d: can't mul, stack too short\n", global.line_count);
	free_stack();
	fclose(global.monty_file);
	exit(EXIT_FAILURE);
}

/**
 * handle_insufficient_mod_error - Handles mod's less than two
 *                                 elements error.
 * Return: Nothing(void).
 */
void handle_insufficient_mod_error(void)
{
	fprintf(stderr, "L%d: can't mod, stack too short\n", global.line_count);
	free_stack();
	fclose(global.monty_file);
	exit(EXIT_FAILURE);
}

/**
 * handle_ascii_error - Handles pchar's out of ascii table range error.
 * Return: Nothing(void).
 */
void handle_ascii_error(void)
{
	fprintf(stderr, "L%d: can't pchar, value out of range\n", global.line_count);
	free_stack();
	fclose(global.monty_file);
	exit(EXIT_FAILURE);
}
