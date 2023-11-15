#include "monty.h"

/**
 * _pstr - mod top of the stack
 * and  second top of the stack
 * @stack: list pointer
 * @line_number: line at which opcode occurs
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int x = 0;

	(void)line_number;


	while (top)
	{
		x = top->n;
		if (x == 0 || _isalpha(x) == 0)
			break;
		putchar(x);
		top = top->next;
	}
	putchar('\n');
}

/**
 * _rotl - mod top of the stack
 * and second top of the stack
 * @stack: list pointer
 * @line_number: line at which opcode occur
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;


	int top = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	top = tmp->n;

	while (tmp->next)
	{
		tmp = tmp->next;
		tmp->prev->n = tmp->n;
	}

	tmp->n = top;
}

/**
 * _rotr - mod top of the stack
 * and second top of the stack
 * @stack:lists pointer
 * @line_number: line at which opcode occu
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	int top = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	while (tmp->next)
		tmp = tmp->next;

	top = tmp->n;

	while (tmp->prev)
	{
		tmp = tmp->prev;
		tmp->next->n = tmp->n;
	}

	tmp->n = top;
}
