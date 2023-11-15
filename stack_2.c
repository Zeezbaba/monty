#include "monty.h"

/**
 * _swap - swap top of stack
 * and the second top of the stack
 * @stack: monty list pointer
 * @line_number: line at which opcode occurs
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	int tmp;

	top = *stack;
	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = top->n;
	top->n = top->next->n;
	top->next->n = tmp;
}

/**
 * _add - addition of top element and next
 * @stack: pointer
 * @line_number: line at which opcode occurs
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int sum = 0, x = 0;

	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (top)
	{
		top = top->next;
		x++;
	}

	if (stack == NULL || (*stack)->next == NULL || x <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	_pop(stack, line_number);

	(*stack)->n = sum;
}

/**
 * _nop - nop the top of stack
 * and second top of the stack
 * @stack: pointer
 * @line_number: line at which opcode occurs
 */

void _nop(__attribute__ ((unused))stack_t **stack,
		__attribute__ ((unused)) unsigned int line_number)
{
	;
}

/**
 * _pchar - prints the ASCII value of a number
 * @stack: pointer
 * @line_number: current line index
 *
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int idx;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	idx = (*stack)->n;
	if (idx > 127 || idx < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(idx);
	putchar('\n');
}

/**
 * _isalpha - checks if element is an alphabet
 * @x: integer
 * Return: 1 if yes, 0 if no
 */
int _isalpha(int x)
{
	if ((x >= 97 && x <= 122) || (x >= 65 && x <= 90))
		return (1);
	else
		return (0);
}
