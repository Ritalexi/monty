#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define LIFO 0
#define FIFO 1

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

/**
 * struct global - global variables.
 * @monty_file: The file pointer of the monty file.
 * @line_count: The current line being executed in the monty file. 
 * @top: The top of the stack.
 *
 * Description: global variable object.
 */

typedef struct global
{
	FILE *monty_file;
	unsigned int line_count;
	stack_t *top;
	stack_t *tail;
	unsigned int mode;
} global_t;

extern global_t global;
typedef void (*func_pointer)(stack_t **stack, unsigned int line_number);

/* Functions from opcodes_identifiers.c */
func_pointer identify_opcode(instruction_t * map, char *buffer);
unsigned int identify_opcode_argument(instruction_t * map, char *buffer);
char *invalid_opcode_flag(char *buffer);
int is_comment(char *buffer);

/* Functions from opcode_functions.c */
void push(stack_t **top_pointer, unsigned int number);
void pall(stack_t **top_pointer, unsigned int argument);
void pint(stack_t **top_pointer, unsigned int argument);
void pop(stack_t **top_pointer, unsigned int argument);
void swap(stack_t **top_pointer, unsigned int argument);

/* Functions from opcode_functions_2.c */
void add(stack_t **top_pointer, unsigned int argument);
void nop(stack_t **top_pointer, unsigned int argument);
void sub(stack_t **top_pointer, unsigned int argument);
void _div(stack_t **top_pointer, unsigned int argument);
void _mul(stack_t **top_pointer, unsigned int argument);

/* Functions from opcode_functions_3.c */
void _mod(stack_t **top_pointer, unsigned int argument);
void pchar(stack_t **top_pointer, unsigned int argument);
void pstr(stack_t **top_pointer, unsigned int argument);
void rotl(stack_t **top_pointer, unsigned int argument);
void rotr(stack_t **top_pointer, unsigned int argument);

/* Functions from opcode_functions_4.c */
void stack(stack_t **top_pointer, unsigned int number);
void queue(stack_t **top_pointer, unsigned int number);

/* Function from free_stack.c */
void free_stack(void);

/* Functions from error_functions.c */
void handle_argc_error(void);
void handle_fopen_error(char *file_name);
void handle_invalid_instruction_error(char *invalid_opcode);
void handle_malloc_error(void);
void handle_isnotint_error(char *opcode);

/* Functions from error_functions_2.c */
void handle_pint_stack_empty_error(void);
void handle_pop_stack_empty_error(void);
void handle_insufficient_swap_error(void);
void handle_insufficient_add_error(void);
void handle_insufficient_sub_error(void);

/* Functions from error_functions_3.c */
void handle_insufficient_div_error(void);
void handle_topofstackis0_div_error(void);
void handle_insufficient_mul_error(void);
void handle_insufficient_mod_error(void);
void handle_ascii_error(void);

#endif /* MONTY_H */
