#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the stack
 * @line_num: line number
 * @value: value to push
 */
void push(stack_t **stack, unsigned int line_num, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	if (*stack != NULL)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	else
		new_node->next = NULL;
	*stack = new_node;

	(void)line_num; /* Silence unused parameter warning */
}

/**
 * pushint - converts a string to an integer and validates it
 * @str: string to convert
 * @line_num: line number
 * Return: converted integer
 */
int pushint(char *str, int line_num)
{
	int i, len, digit;

	len = strlen(str);
	if (len == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < len; i++)
	{
		if (str[i] == '-' && i == 0)
			continue;
		digit = isdigit((unsigned char)str[i]);
		if (digit == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
	}

	return atoi(str);
}
