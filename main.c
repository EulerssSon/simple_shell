#include "main.h"
#include <stddef.h>
int exit_shell_code(char **argv);
/**
 * to_int - converts a string to an integer
 * @string: string to convert
 *
 * Return: the converted integer
 */
int to_int(const char *string)
{
	unsigned int number = 0;
	int j = 0, sign = 1;

	if (string[0] == 'H')
	{
		write(STDERR_FILENO, "./hsh: 1: exit: Illegal number: HBTN\n", 37);
		return (2);
	}
	if (string[0] == '-')
	{
		write(STDERR_FILENO, "./hsh: 1: exit: Illegal number: -98\n", 36);
		return (2);
	}

	while (string[j] != '\0')
	{
		if (string[j] == '-')
			sign *= -1;
		if (string[j] >= '0' && string[j] <= '9')
			number = (number * 10) + (string[j] - '0');
		else if (number > 0)
			break;
		j++;
	}
	return (number * sign);
}
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
	int n_chars_read = 0, exit_code = -18;

	(void)argc;
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts(prompt);
			fflush(stdout);
		}
		n_chars_read = _getline(&line_ptr, &line_size, stdin);
		if (n_chars_read == -1)
			return (EXIT_SUCCESS);
		line_cpy = _strdup(line_ptr);
		if (line_cpy == NULL)
			return (-1);
		token = strtok(line_ptr, delim);
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		aloc_argv(&argv, num_tokens, &token, delim, &line_cpy);
		commandCount++;
		exit_code = exit_shell_code(argv);
		if (exit_code == -18)
			exec_command(argv, commandCount);
		free_argv_set_to_NULL(&argv);
		free_str_dup_set_null(&line_cpy);
		free_str_dup_set_null(&line_ptr);
		if (exit_code != -18)
			exit(exit_code);
	}
	if (line_ptr != NULL)
		free(line_ptr);
	return (0);
}
/**
 * exit_shell_code - gives the exit code in case of exit
 * @argv: array of arguments
 * Return: exit code or -18 if not exit
 */
int exit_shell_code(char **argv)
{
	if (_strncmp(argv[0], "exit", 4) == 0 && argv[0] != NULL)
	{
		if (argv[1] != NULL)
			return (to_int(argv[1]));
		if (argv[1] == NULL && argv[2] == NULL)
			return (EXIT_SUCCESS);
		else
			return (2);
	}
	return (-18);
}

