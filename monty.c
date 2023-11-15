#include "monty.h"

global_var var_global;
/**
 * main - driver function for this program
 * @ac: integer number of arguments
 * @av: opcode file
 * Return: 0
 */
int main(int ac, char **av)
{
	stack_t *stack;

	stack = NULL;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_access(av[1], &stack);
	free_dlistint(stack);
	return (0);
}
