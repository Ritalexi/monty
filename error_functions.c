#include "monty.h"

/**
 * handle_argc_error - Handles argc error.
 *
 * Return: Nothing
 */
void handle_argc_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * handle_fopen_error - Handles file opening error.
 * @file_name: The file_name gotten from argv[1].
 *
 * Return: Nothing
 */
void handle_fopen_error(char *file_name)
{
	fprintf(stderr, "Error: Can't open file %s\n", file_name);
	exit(EXIT_FAILURE);
}

/**
 * handle_invalid_instruction_error - Handles invalid opcode error.
 * @invalid_opcode: The invalid opcode.
 *
 * Return: Nothing.
 */
void handle_invalid_instruction_error(char *invalid_opcode)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", global.line_count,
			invalid_opcode);
	free_stack();
	fclose(global.monty_file);
	exit(EXIT_FAILURE);
}

/**
 * handle_malloc_error - Handles malloc error.
 * Return: Nothing.
 */
void handle_malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_stack();
	fclose(global.monty_file);
	exit(EXIT_FAILURE);
}

/**
 * handle_isnotint_error - Handles argument is not an integer or no
 *                         integer argument found errors.
 * @opcode: The opcode found.
 *
 * Return: Nothing.
 */
void handle_isnotint_error(char *opcode)
{
	fprintf(stderr, "L%d: usage: %s integer\n", global.line_count, opcode);
	free_stack();
	fclose(global.monty_file);
	exit(EXIT_FAILURE);
}
