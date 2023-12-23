#include "main.h"
/**
 * aloc_argv - allocates argv
 * @argv: array of arguments
 * @n: number of arguments
 * @token: token
 * @d: delimiter
 * @lc: line cpy
 * Description: allocates argv and returns it
 * Return: void
 */
void aloc_argv(char ***argv, size_t n, char **token, const char *d, char **lc)
{
	size_t i = 0;

	*argv = malloc(sizeof(char *) * (n + 1));
	if (*argv == NULL)
	{
		perror("malloc ");
		exit(EXIT_FAILURE);
	}
	*token = strtok(*lc, d);
	for (i = 0; *token != NULL; i++)
	{
		(*argv)[i] = _strdup(*token);
		if ((*argv)[i] == NULL)
		{
			perror("strdup ");
			for (i--; i > 0; i--)
			{
				free((*argv)[i]);
				(*argv)[i] = NULL;
			}
			free(*argv);
			*argv = NULL;
		}
		*token = strtok(NULL, d);
	}
	(*argv)[i] = NULL;
}
/**
 * free_argv_set_to_NULL - frees argv and sets it to NULL
 * @argv: array of arguments
 * Return: void
 */
void free_argv_set_to_NULL(char ***argv)
{
	size_t i = 0;

	for (i = 0; (*argv)[i] != NULL; i++)
	{
		free((*argv)[i]);
		(*argv)[i] = NULL;
	}
	free(*argv);
	*argv = NULL;
}

/**
 * free_str_dup_set_null - frees a string and sets its pointer to NULL
 * @str: pointer to the string to be freed
 */
void free_str_dup_set_null(char **str)
{
	free(*str);
	*str = NULL;
}

