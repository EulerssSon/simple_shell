#include "main.h"

void free_2d(char ***args)
{
	int i;

	for(i = 0; (*args)[i] != NULL; i++)
	{
		free((*args)[i]);
	}
	free(*args);
}
/**
 * _strcpy - copies string from src to dest 
 *
 *@dest: pointer to destination string
 *@src: pointer to source string
 * Return: pointer to dest string
 */

char *_strcpy(char *dest, char *src)
{
	int len = 0, i = 0;

	while (src[i] != '\0')
	{
		len++;
		i++;
	}
	i = 0;
	len++;

	while (i != len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

/**
 * _strlen - print length of string
 *
 * @s: pointer to string
 * Return: length of string
 */

int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}

	return (len);
}/**
 */

char **tokenize(char *line)
{
 	char **args,  *line_copy = NULL, *token;
	int token_num = 0, i;
	char * delim = " \n";

	line_copy = malloc (sizeof(char) * (_strlen(line) + 1));

	if(line_copy == NULL)
	{
		perror("Malloc error");
		exit(EXIT_FAILURE);
	}
	_strcpy(line_copy, line);
	token = strtok(line, delim);
	while (token)
	{
		token_num++;
		token = strtok(NULL, delim);
	}
	token_num++;
	args = malloc (sizeof(char *) * (token_num + 1));
	if (args == NULL)
	{
		perror("Malloc error1");
		free(line_copy);
		exit(EXIT_FAILURE);
	}
	token = strtok(line_copy, delim);
	for (i = 0; token != NULL; i++)
	{
		args[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (args[i] == NULL)
		{
			perror("Malloc error2");
			free(line_copy);
			while (--i >= 0)
			{
				free(args[i]);
			}
			free(args);
			exit(EXIT_FAILURE);
		}
		_strcpy(args[i], token);
		token = strtok(NULL, delim);
	}
	args[i] = NULL;
	free(line_copy);
	return (args);
}
