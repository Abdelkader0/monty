#include "monty.h"
#include <stdio.h>

/**
 * main - Monty interpreter
 * @argc: the number of arguments
 * @argv: the arguments
 * Return: void
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	static char *lines[1000] = {NULL};
	int line_count = 0;
	FILE *file;
	size_t bufsize = 1000;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	for (line_count = 0; getline(&(lines[line_count]), &bufsize, file) > 0; line_count++)
		;
	execute(lines, stack);
	free_list(lines);
	fclose(file);
	return (0);
}

/**
 * execute - executes opcodes
 * @lines: contents of file
 * @stack: the list
 * Return: void
 */
void execute(char *lines[], stack_t *stack)
{
	int line_number, i;

	instruction_t instructions[] = {
		{"pall", pall},
		{"pint", pint},
		{"add", add},
		{"swap", swap},
		{"pop", pop},
		{"null", NULL}
	};

	for (line_number = 1, i = 0; lines[i + 1]; i++, line_number++)
	{
		if (_strcmp("push", lines[i]))
			push(&stack, line_number, pushint(lines[i], line_number));
		else if (_strcmp("nop", lines[i]))
			;
		else
		{
			int j = 0;
			while (!_strcmp(instructions[j].opcode, "null"))
			{
				if (_strcmp(instructions[j].opcode, lines[i]))
				{
					instructions[j].func(&stack, line_number);
					break;
				}
				j++;
			}
			if (_strcmp(instructions[j].opcode, "null") && !_strcmp(lines[i], "\n"))
			{
				fprintf(stderr, "L%u: unknown instruction %s", line_number, lines[i]);
				if (!nlfind(lines[i]))
					fprintf(stderr, "\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	free_stack(stack);
}
