#include "main.h"
#include <stddef.h>
/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, -1 on failure
 */
int main(int argc, char **argv)
{
	char *prompt = "$ ";
	char *line_ptr = NULL, *line_cpy = NULL, *token = NULL;
	const char *delim = " \t\n";
	size_t line_size = 0, num_tokens = 0, commandCount = 0;
	int n_chars_read = 0;

	(void)argc;
	while (1)
	{
		_puts(prompt);
		if (isatty(STDIN_FILENO))
		{
			_puts(prompt);
			fflush(stdout);
		}
		n_chars_read = _getline(&line_ptr, &line_size, stdin);
		if (n_chars_read == -1)
			return (-1);
		line_cpy = _strdup(line_ptr);
		if (line_cpy == NULL)
			return (-1);
		token = _strtok(line_ptr, delim);
		while (token != NULL)
		{
			num_tokens++;
			token = _strtok(NULL, delim);
		}
		aloc_argv(&argv, num_tokens, &token, delim, &line_cpy);
		commandCount++;
		exec_command(argv, commandCount);
		free_argv_set_to_NULL(&argv);
		free_str_dup_set_null(&line_cpy);
		free_str_dup_set_null(&line_ptr);
	}
	if (line_ptr != NULL)
	{
		free(line_ptr);
		line_ptr = NULL;
	}
	return (0);
}


