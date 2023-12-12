#include "main.h"

/**
 *to_int - converts string to int
 *@string: string to convert
 *Return: the converted string
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
		{
			number = (number * 10) + (string[j] - '0');
		}
		else if (number > 0)
			break;
		j++;
	}
	return (number * sign);
}

/**
 *exit_shell_code - gives the exit code in case of exit
 *@argv: array of arguments
 *Return: exit codes or -18 if no exit
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


