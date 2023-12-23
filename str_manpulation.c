#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	int num_of_written = write(STDOUT_FILENO, &c, 1);

	if (num_of_written == -1)
	{
		perror("write");
		return (-1);
	}

	return (num_of_written);
}

/**
 * count_digits - counts the number of digits in a number
 * @num: the number to count its digits
 * Return: the number of digits in num
 * if num is 0, return 1
 * if num is negative, return -1
 *
 */
int count_digits(int num)
{
	int count = 0;

	if (num == 0)
		return (1);

	while (num != 0)
	{
		num /= 10;
		++count;
	}
	return (count);
}
/**
 * num_to_string - converts a number to a string
 * @num: the number to be converted
 * Return: a pointer to the converted string
 * if num is 0, return "0"
 * if num is negative, return NULL
 * if malloc fails, return NULL
 */
char *num_to_string(int num)
{
	char *str;
	char temp;
	int num_digits = count_digits(num), i = 0;

	str = malloc(sizeof(char) * (num_digits + 1));/* +1 for null byte */
	if (str == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	if (num == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	while (num != 0)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
		i++;
	}
	/**
	 * reversing the string
	 * swapping the first and last element
	 * then the second and second last element
	 * and so on
	 */
	for (i = 0; i < num_digits / 2; i++)
	{
		temp = str[i];
		str[i] = str[num_digits - i - 1];
		str[num_digits - i - 1] = temp;
	}
	str[num_digits] = '\0';
	return (str);
}
/**
 * _memcpy - copies n bytes from memory area src to memory area dest
 * @dest: pointer to the destination array where the content is to be copied
 * @src: pointer to the source of data to be copied
 * @n: number of bytes to copy
 * Return: a pointer to dest
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
	size_t i = 0;
	char *dest_ptr = (char *)dest;
	const char *src_ptr = (char *)src;

	if (dest == NULL || src == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < n; i++)
	{
		dest_ptr[i] = src_ptr[i];
	}
	return (dest);
}
/**
 * _strcpy - copies the string pointed to by src,
 * including the terminating null byte (\0)
 * , to the buffer pointed to by dest
 * @dest: pointer to the destination array where the content is to be copied
 * @src: pointer to the source of data to be copied
 * Return: a pointer to dest
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	if (dest == NULL || src == NULL)
	{
		perror("strcpy");
		return (NULL);
	}
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i++] = '\0';
	return (dest);
}

