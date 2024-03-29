#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: pointer to head of stack
 * @line_num: file's line number
 * Return: Void
 */
void add(stack_t **stack, unsigned int line_num)
{
stack_t *current = *stack, *next_node;
if ((*stack) == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
exit(EXIT_FAILURE);
}

if (*stack && (*stack)->next)
{
next_node = current->next;
next_node->n += current->n;
free(current);
*stack = next_node;
}
}

/**
 * pint - Prints value at top of stack.
 * @stack: pointer to head of stack
 * @line_num: file's line number
 * Return: Void
 */
void pint(stack_t **stack, unsigned int line_num)
{
if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
exit(EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
}
