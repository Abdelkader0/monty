#include "monty.h"

/**
 * str_cmp - compares strings
 * @str1: a string to be compared
 * @str2: a string to be compared
 * Return: 0
 */
int str_cmp(char *str1, char *str2)
{
	while (*str2 != '\0')
	{
		if (*str2 == ' ')
			str2++;
		else if (*str1 == *str2)
		{
			str1++;
			str2++;
			if (*str1 == '\0' && (*str2 == ' ' || *str2 == '\n' || *str2 == '\0'))
				return (1);
		}
		else
			return (0);
	}
	return (0);
}

/**
 * find_newline - finds newline character
 * @str: the string to find '\n'
 * Return: 1 if found, 0 otherwise
 */
int find_newline(char *str)
{
	char *newline = "\n";

	while (*str != '\0')
	{
		if (*newline == *str)
		{
			newline++;
			str++;
			if (*newline == '\0')
				return (1);
		}
		else
			str++;
	}
	return (0);
}

/**
 * get_push_integer - gets the integer for push opcode
 * @str: the content of the file
 * @line_num: line number
 * Return: the number
 */
int get_push_integer(char *str, int line_num)
{
	char *opcode = "push";

	while (*str != '\0')
	{
		if (*opcode == *str)
		{
			opcode++;
			str++;
			if (*opcode == '\0')
				while (*str)
				{
					if ((*str >= '0' && *str <= '9') || *str == '-')
					{
						validate_combinations(str, line_num);
						return (atoi(str));
					}
					else if (*str == ' ')
						str++;
					else
					{
						fprintf(stderr, "L%d: usage: push integer\n", line_num);
						exit(EXIT_FAILURE);
					}
				}
		}
		else
			str++;
	}
	return (0);
}

/**
 * validate_combinations - validates non-number and number combinations
 * @str: the string
 * @line_num: line number
 * Return: 1
 */
int validate_combinations(char *str, int line_num)
{
	int i = 1;

	while (str[i])
	{
		if (str[i] == '\0' || str[i] == '\n')
			break;
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
			i++;
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}

