#include "monty.h"

/**
 * _push - insert data into a stack
 * @stack: linked lists
 * @line_number: line at which opcode occurs
 */
void _push(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *top;
	(void)line_number;

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	top->n = var_global.push_arg;
	top->next = *stack;
	top->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = top;
	*stack = top;
}

/**
 * _pall - print all function
 * @stack: linked list pointer
 * @line_number: line at which opcode occur
 */
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * _pint - prints top of a stack
 * @stack: linked list pointer
 * @line_number: line at which opcode occurs
 *
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", tmp->n);
}

/**
 * _pop - remove the top element of a stack
 *@stack: first node pointer
 *@line_number: integer
 *Return: void
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = node->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(node);
}

/**
 * free_dlistint - frees a list
 * @head: first node pointer
 *
 */
void free_dlistint(stack_t *head)
{
	stack_t *top;

	while (head != NULL)
	{
		top = head->next;
		free(head);
		head = top;
	}
}
