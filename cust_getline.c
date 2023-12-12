#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _getline - reads an entire line from a file descriptor
 * @lineptr: pointer to the buffer containing the line
 * @n: pointer to the variable containing the size of the buffer
 * @stream: pointer to the file descriptor
 * Return: the number of characters read, -1 if an error occurred
 */

int _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *bufferPtr = NULL;
	char *positionChar = NULL;
	size_t sizeLine = 0;
	int character;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	bufferPtr = *lineptr;
	sizeLine = *n;
	character = fgetc(stream);
	if (character == EOF)
		return (-1);
	if (bufferPtr == NULL)
	{
		bufferPtr = malloc(sizeof(char) * 1024);
		if (bufferPtr == NULL)
			return (-1);
		sizeLine = 1024;
	}
	positionChar = bufferPtr;
	while (character != EOF)
	{
		if ((size_t)(positionChar - bufferPtr) >= (sizeLine - 1))
		{
			sizeLine += 1024;
			bufferPtr = _realloc(bufferPtr, *n, sizeLine);
			if (bufferPtr == NULL)
				return (-1);
			positionChar = bufferPtr + sizeLine - 1024;
		}
		*positionChar++ = character;
		if (character == '\n')
			break;
		character = fgetc(stream);
	}
	*positionChar++ = '\0';
	*lineptr = bufferPtr;
	*n = sizeLine;
	return (positionChar - bufferPtr - 1);
}
