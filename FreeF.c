#include "monty.h"

/**
 * free_stack - frees the singly linked list
 * @head: pointer to the head of the list
 * Return: Nothing
 */
void free_stack(stack_t *head)
{
	stack_t *current = head;
	stack_t *next;

	if (head == NULL)
		return;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

/**
 * free_list - frees the list of strings
 * @list: pointer to the array of strings
 * Return: Nothing
 */
void free_list(char *list[])
{
	int i = 0;

	while (list[i] != NULL)
	{
		free(list[i]);
		i++;
	}
}
