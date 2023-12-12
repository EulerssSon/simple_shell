#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * get_command_path - gets the path of a command
 * @command: pointer to the string containing the command
 * @code: pointer to the integer containing the code
 * Return: pointer to the string containing the path of the command
 */
char *get_command_path(char *command, int *code)
{
	char *paths = _strdup(getenv("PATH"));
	char *path = strtok(paths, ":"), *abs_path;

	*code = 0;
	if (paths == NULL || path == NULL || command == NULL)
	{
		free_str_dup_set_null(&paths);
		*code = 0;
		return (NULL);
	}
	while (path != NULL)
	{
		abs_path = malloc(_strlen(path) + _strlen(command) + 2);
		if (abs_path == NULL)
		{
			free_str_dup_set_null(&paths);
			*code = 0;
			return (NULL);
		}
		_strcpy(abs_path, path);
		_strcat(abs_path, "/");
		_strcat(abs_path, command);
		if (!access(abs_path, X_OK | F_OK))
		{
			free_str_dup_set_null(&paths);
			*code = 1;
			return (abs_path);
		}
		free_str_dup_set_null(&abs_path);
		path = strtok(NULL, ":");
	}
	free_str_dup_set_null(&paths);
	/* check if command is a path */
	if (access(command, X_OK | F_OK) == 0)
	{
		*code = 2;
		return (command);
	}
	/* check if command is a path */
	return (NULL);
}

/**
 * exec_command - executes a command
 * @argv: pointer to an array of pointers to strings containing the arguments
 * @commandCount: the number of the command
 * Return: 1 on success, 0 on failure or 127 on error
 */
int exec_command(char **argv, size_t commandCount)
{
	pid_t pid;
	int status, code;
	char *command_path, *num;

	command_path = get_command_path(argv[0], &code);
	if (command_path != NULL)
	{
		pid = fork();
		if (pid == -1)
			return (1);
		if (pid == 0)
		{
			if (execve(command_path, argv, environ) == -1)
				exit(1);
		}
		else
		{
			waitpid(pid, &status, 0);
			if (code == 1)
				free_str_dup_set_null(&command_path);
			return (0);
		}
	}
	else
	{
		if (argv[0] == NULL || argv[0][0] == ' ')
			return (0);
		if (code == 0 && argv[0][0] != '/')
		{
			num = num_to_string(commandCount);
			print_err_num(&num, argv[0]);
		}
			if (execve(argv[0], argv, environ) == -1)
				exit(127);
	}
	return (0);
}
/**
 * print_err_num - prints the error message
 * @num: pointer to the string containing the number of the command
 * @command: pointer to the string containing the command
 * Return: 127 on error
 */
int print_err_num(char **num, char *command)
{
	pid_t pid;
	int status;

	write(STDERR_FILENO, "./hsh: ", 7);
	write(STDERR_FILENO, *num, _strlen(*num));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": not found\n", 12);
	free(*num);
	*num = NULL;
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (1);
	}
	if (pid == 0)
	{
		exit(127);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			return (127);
		return (127);

	}
}
/**
 * print_env - prints the environment
 */
void print_env(void)
{
	int i = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		_puts(environ[i]);
		_putchar('\n');
	}
}

