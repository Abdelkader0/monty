#include "monty.h"

/**
 * pall - Print all values on the stack
 * @stack: pointer to head of stack
 * @line_number: file's line number
 * Return: Void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}

/**
 * push - Pushes an element to the stack
 * @stack: pointer to head of stack
 * @line_number: file's line number
 * @value: variable
 * Return: address of new element
 */

void push(stack_t **stack, unsigned int line_number, int value)
{
	stack_t *new_node, *head = *stack;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		exit(EXIT_FAILURE);
	new_node->prev = NULL;
	new_node->value = value;
	new_node->next = *stack;
	if (*stack)
		head->prev = new_node;
	*stack = new_node;
}

/**
 * pop - Removes the top element of the stack
 * @stack: pointer to head of stack
 * @line_number: file's line number
 * Return: Void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (head)
	{
		*stack = head->next;
		free(head);
	}
}

/**
 * swap - Swaps the top two elements of the stack
 * @stack: pointer to head of stack
 * @line_number: file's line number
 * Return: Void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *temp;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (head && head->next)
	{
		temp = head->next;
		if (temp->next)
			temp->next->prev = head;
		head->next = temp->next;
		temp->prev = NULL;
		temp->next = head;
		head->prev = temp;
		*stack = temp;
	}
}
