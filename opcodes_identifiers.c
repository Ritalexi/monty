#include "monty.h"

/**
 * identify_opcode - Returns the function for the corresponding
 *                   opcode found in the buffer.
 * @map: An array of instruction_t objects containing opcodes
 *       and the their corresponding functions.
 * @buffer: An array of characters gotten from the monty_file
 *          possibly containing opcode and its arguments..
 *
 * Return: The function corresponding to the opcode found in buffer,
 *         Otherwise returns NULL if no opcode is found in buffer.
 */
func_pointer identify_opcode(instruction_t *map, char *buffer)
{
	unsigned int count;

	count = 0;
	while (map[count].opcode)
	{
		if (strstr(buffer, map[count].opcode))
			return (map[count].f);
		count++;
	}
	return (NULL);
}

/**
 * invalid_opcode_flag - Returns an invalid opcode.
 * @buffer: An already opcode scanned buffer.
 *
 * Return: A pointer to the invalid opcode if any,
 *         Otherwise returns NULL.
 */
char *invalid_opcode_flag(char *buffer)
{
	char *ptr, *tmp;
	char *symbols = "'!\"#$%&\'()*+,-./0123456789:;<=>?@AB\
			 CDEFGHIJKLMNOPQRSTUVWXYZ[]^_`abcdefghijklmnopqrstuvwxyz{|}~'";

	ptr = strpbrk(buffer, symbols);
	if (ptr)
	{
		tmp = ptr;
		ptr++;
		while (*ptr >= '!' && *ptr <= '~')
			ptr++;
		*ptr = '\0';
		return (tmp);
	}
	return (NULL);
}

/**
 * identify_opcode_argument - Returns the first integer argument
 *                            to the opcode found
 * @map: An array of instruction_t objects containing opcodes
 *       and the their corresponding functions.
 * @buffer: An array of characters gotten from the monty_file.
 *
 * Return: The first integer argument found if not dealing with
 *         the (pall) opcode, Otherwise 0 if dealing with the (pall).
 */
unsigned int identify_opcode_argument(instruction_t *map, char *buffer)
{
	unsigned int count;
	char *ptr, *tmp = NULL;
	char *opcodes_list;

	opcodes_list = "pallpintpopswapaddnopsubdivmulmodpcharpstrrotlrotrstackqueue";
	count = 0;
	while (map[count].opcode)
	{
		ptr = strstr(buffer, map[count].opcode);
		if (ptr)
		{
			if (strstr(opcodes_list, map[count].opcode))
				return (0);
			break;
		}
		count++;
	}
	ptr = ptr + strlen(map[count].opcode);
	while (*ptr)
	{
		if (!strchr(" 0123456789", *ptr))
			break;
		if (*ptr >= '0' && *ptr <= '9')
		{
			tmp = ptr;
			ptr++;
			while (*ptr >= '0' && *ptr <= '9')
				ptr++;
			*ptr = '\0';
			break;
		}
		ptr++;
	}
	if (!tmp)
		handle_isnotint_error(map[count].opcode);
	return (atoi(tmp));
}

/**
 * is_comment - Checks if a line in the monty_file is commented.
 * @buffer: The line to check.
 *
 * Return: 1 if Line is commented Otherwise 0.
 */
int is_comment(char *buffer)
{
	while (buffer)
	{
		if ((*buffer != ' ') && (*buffer != '#'))
			return (0);
		if (*buffer == '#')
		{
			(global.line_count)++;
			return (1);
		}
		buffer++;
	}
	return (0);
}
