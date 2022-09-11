#include "monty.h"

global_t global = {NULL, 1, NULL, NULL, LIFO};

/**
 * main - The main function for the Monty Interpreter program.
 * @argc: The number of command line arguments.
 * @argv: A string array of the command line arguments.
 *
 * Return: It returns 0(EXIT_SUCCESS) on success,
 *         Otherwise it returns 1(EXIT_FAILURE) on failure.
 */

int main(int argc, char **argv)
{
	char buffer[128], *invalid_opcode;
	func_pointer opcode;
	unsigned int argument;

	instruction_t map_to[] = {{"push", push}, {"pall", pall}, {"pint", pint},
		                  {"pop", pop}, {"swap", swap}, {"add", add},
				  {"nop", nop}, {"sub", sub}, {"div", _div},
				  {"mul", _mul}, {"mod", _mod}, {"pchar", pchar},
				  {"pstr", pstr}, {"rotl", rotl}, {"rotr", rotr},
				  {"stack", stack}, {"queue", queue}, {NULL, NULL}};
	if (argc != 2)
		handle_argc_error();
	global.monty_file = fopen(argv[1], "r");
	if (!global.monty_file)
		handle_fopen_error(argv[1]);
	while (fgets(buffer, sizeof(buffer), global.monty_file))
	{
		if (is_comment(buffer))
			continue;
		opcode = identify_opcode(map_to, buffer);
		if (opcode)
			argument = identify_opcode_argument(map_to, buffer);
		else
		{
			invalid_opcode = invalid_opcode_flag(buffer);
			if (invalid_opcode)
				handle_invalid_instruction_error(invalid_opcode);
			continue;
		}
		opcode(&global.top, argument);
		(global.line_count)++;
	}
	fclose(global.monty_file);
	free_stack();
	exit(EXIT_SUCCESS);
}
