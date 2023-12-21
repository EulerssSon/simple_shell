#include "main.h"

/**
 * _strncpy - copies up to n characters from the string pointed to,srcToDest
 * @dest: pointer to the destination array where the content is to be copied
 * @src: pointer to the source of data to be copied
 * @n: number of bytes to copy
 * Return: a pointer to dest
 */
char _strncpy(char *dest, const char *src, int n)
{
	int i = 0;

	if (dest == NULL || src == NULL || n < 0)
	{
		return (-1);
	}
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i++] = '\0';
	return (0);
}
/**
 * _getchar - reads a character from stdin
 * Return: the character read
 */

int _getchar(void)
{
	char c;
	int r = read(STDIN_FILENO, &c, 1);

	if (r == 0)
	{
		return (EOF);
	}

	if (r == -1)
	{
		perror("read");
		return (-1);
	}
	return (c);
}

/**
 * _puts - writes the string str to stdout
 * @str: pointer to the string to print
 * Return: On success the number of characters written.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _puts(char *str)
{
	int i = 0;
	int num_of_written = 0;

	while (str[i] != '\0')
	{
		if (_putchar(str[i]) == -1)
		{
			return (-1);
		}
		i++;
	}

	num_of_written = i;
	return (num_of_written);
}
/**
 * _strlen - returns the length of a string
 * @s: pointer to the string
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	if (s == NULL)
	{
		return (0);
	}
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _strncmp - compares at most the first n bytes of str1 and str2
 * @s1: pointer to the first string to compare
 * @s2: pointer to the second string to compare
 * @n: number of bytes to compare
 * Return: an integer less than, equal to,
 * or greater than zero if str1 is found,
 * respectively, to be less than, to match, or be greater than str2
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i = 0;

	if (s1 == NULL || s2 == NULL || n < 0)
	{
		return (-1);
	}

	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}

	return (0);
}

