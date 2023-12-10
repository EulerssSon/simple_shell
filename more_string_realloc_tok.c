#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: pointer to the destination array where the content is to be copied
 * @src: pointer to the source of data to be copied
 * Return: a pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	if (dest == NULL || src == NULL)
	{
		return (NULL);
	}

	while (dest[i] != '\0')
	{
		i++;
	}

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';

	return (dest);
}
/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 * @str: pointer to the string to duplicate
 * Return: a pointer to the duplicated string
 */
char *_strdup(char *str)
{
	int i = 0;
	char *dup;

	if (str == NULL)
	{
		return (NULL);
	}

	dup = malloc(sizeof(char) * (_strlen(str) + 1));
	if (dup == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/**
 * isDelim - checks if a character is a delimiter
 * @c: the character to check
 * @delim: the delimiters
 * Return: 1 if the character is a delimiter, 0 otherwise
 */
int isDelim(char c, const char *delim)
{
	int i = 0;

	if (delim == NULL)
	{
		return (0);
	}

	while (delim[i] != '\0')
	{
		if (c == delim[i])
		{
			return (1);
		}
		i++;
	}

	return (0);
}
/**
 * _strtok - splits a string into tokens
 * @str: pointer to the string to split
 * @delim: pointer to the string containing the delimiters
 * Return: a pointer to the next token, NULL if there are no more tokens
 */
char *_strtok(char *str, const char *delim)
{
	static char *buffer;
	char *token;
	int flag = 0;

	if (str != NULL)
	{
		buffer = str;
	}
	if (buffer == NULL)
	{
		return (NULL);
	}
	if (*buffer == '\0')
	{
		return (NULL);
	}
	token = buffer;
	while (*buffer != '\0')
	{
		flag = isDelim(*buffer, delim);
		if (flag == 1)
		{
			*buffer = '\0';
			buffer++;
			while (isDelim(*buffer, delim) == 1)
			{
				*buffer = '\0';
				buffer++;
			}
			return (token);
		}
		else
		{
			buffer++;
		}
	}
	return (token);
}
/**
 * _realloc - reallocates a memory block using malloc and free
 * @old_ptr: pointer to the memory previously allocated
 * @old_size: size, in bytes, of the allocated space for old_ptr
 * @new_size: new size, in bytes of the new memory block
 * Return: a pointer to the new allocated memory
 */
void *_realloc(void *old_ptr, size_t old_size, size_t new_size)
{
	void *new_ptr = NULL;

	if (old_ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
		{
			perror("malloc");
			return (NULL);
		}
		return (new_ptr);
	}
	if (new_size == 0)
	{
		free(old_ptr);
		old_ptr = NULL;
		return (NULL);
	}
	if (new_size == old_size)
		return (old_ptr);
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	if (new_size > old_size)
	{
		_memcpy(new_ptr, old_ptr, old_size);
	}
	else
	{
		_memcpy(new_ptr, old_ptr, new_size);
	}
	free(old_ptr);
	old_ptr = NULL;
	return (new_ptr);
}

