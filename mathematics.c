#include "monty.h"

/**
 * _sub - substract the top of stack
 * and the second top stack
 * @stack: points to the list of monty
 * @line_number: line at which the opcode occurs
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int sub = 0, init = 0;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (tmp)
	{
		tmp = tmp->next;
		init++;
	}

	if (stack == NULL || (*stack)->next == NULL || init <= 1)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sub = (*stack)->next->n - (*stack)->n;
	_pop(stack, line_number);

	(*stack)->n = sub;
}

/**
 * _mul - multiply top of stack
 * and the second top stack
 * @stack: points to lists for monty
 * @line_number: line at which opcode occurs
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int mul;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		mul = (*stack)->n;
		_pop(stack, line_number);
		(*stack)->n *= mul;
	}
}

/**
 * _div - divide the top of the stack
 * and the second top stack
 * @stack: points to lists for monty
 * @line_number: line at which opcode occurs
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int div = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		div = (*stack)->n;
		_pop(stack, line_number);
		(*stack)->n /= div;
	}
}

/**
 * _mod - mod top of stack and the second top stack
 * @stack: points to lists for monty
 * @line_number: line at which opcode occurs
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int mod = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		mod = (*stack)->n;
		_pop(stack, line_number);
		(*stack)->n %= mod;
	}
}
