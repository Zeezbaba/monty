#include <stdio.h>
#include "monty.h"
#include <stdlib.h>
#include <string.h>

/**
 * read_access - access and run a bytecode file and commands
 * @files: pathname to file
 * @stack: top pointer
 */
void read_access(char *files, stack_t **stack)
{
	char *lines;
	size_t j = 0;
	int count = 1;
	instruct_func s;
	int validates;
	int access;


	var_global.file = fopen(files, "r");

	if (var_global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", files);
		exit(EXIT_FAILURE);
	}

	while ((access = getline(&var_global.buffer, &j, var_global.file)) != -1)
	{
		lines = line_parser(var_global.buffer, stack, count);
		if (lines == NULL || lines[0] == '#')
		{
			count++;
			continue;
		}
		s = op_codes(lines);
		if (s == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", count, lines);
			exit(EXIT_FAILURE);
		}
		s(stack, count);
		count++;
	}
	free(var_global.buffer);
	validates = fclose(var_global.file);
	if (validates == -1)
		exit(-1);
}

/**
 * op_codes -  opcode checker
 * @str: opcode
 * Return: a functions, or NULL on failure
 */
instruct_func op_codes(char *str)
{
	int ints;

	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL},
	};

	ints = 0;
	while (instruct[ints].f != NULL && strcmp(instruct[ints].opcode, str) != 0)
	{
		ints++;
	}

	return (instruct[ints].f);
}

/**
 * _isinteger - validate if a string is an integer
 * @str: string to be validated
 * Return: returns 1 if string is an integer, 0 otherwise
 */
int _isinteger(char *str)
{
	unsigned int k;

	if (str == NULL)
		return (0);
	k = 0;
	while (str[k])
	{
		if (str[0] == '-')
		{
			k++;
			continue;
		}
		if (!isdigit(str[k]))
			return (0);
		k++;
	}
	return (1);
}

/**
 * line_parser - parses a line for an opcode and arguments
 * @line: the line to be parsed
 * @stack: head pointer
 * @line_number: line number
 * Return: opcode or null on failure
 */
char *line_parser(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcodes, *push, *arg;
	(void)stack;

	push = "push";
	opcodes = strtok(line, "\n ");
	if (opcodes == NULL)
		return (NULL);

	if (strcmp(opcodes, push) == 0)
	{
		arg = strtok(NULL, "\n ");
		if (_isinteger(arg) == 1 && arg != NULL)
		{
			var_global.push_arg = atoi(arg);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (opcodes);
}
