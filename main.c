#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

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
 * coutn_digits - count the number of digits in a number
 * @num: the number to count its digits
 * Return: the number of digits
 */
int count_digits(int num)
{
	int count = 0;

	while (num != 0)
	{
		num /= 10;
		++count;
	}
	return count;
}
/**
 * num_to_string - convert a number to a string
 * @num: the number to convert
 * Return: the string
 */
char *num_to_string(int num)
{
	char *str;
	char temp;
	int num_digits = count_digits(num), i = 0;

	str = malloc(sizeof(char) * (num_digits + 1)); // +1 for '\0'
	if (str == NULL)
	{
		perror("malloc");
		return NULL;
	}

	while (num != 0)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
		i++;
	}
	for (i = 0; i < num_digits / 2; i++)
	{
		temp = str[i];
		str[i] = str[num_digits - i - 1];
		str[num_digits - i - 1] = temp;
	}
	str[num_digits] = '\0';
	return str;
}
/**
 * _memcpy - copies n bytes from memory area src to memory area dest
 * @dest: pointer to the destination array where the content is to be copied
 * @src: pointer to the source of data to be copied
 * @n: number of bytes to copy
 * Return: a pointer to dest
 */
void *_memcpy(void *dest, const void *src, size_t n){
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
 * _strcpy - copies the string pointed to by src, including the terminating null byte (\0), to the buffer pointed to by dest
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
/**
 * _strncpy - copies up to n characters from the string pointed to, by src to dest
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
 * Return: an integer less than, equal to, or greater than zero if str1 is found, respectively, to be less than, to match, or be greater than str2
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
 * _strdup - returns a pointer to a newly allocated space in memory, which contains a copy of the string given as a parameter
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
		return 0;
	}

	while (delim[i] != '\0')
	{
		if (c == delim[i])
		{
			return 1;
		}
		i++;
	}

	return 0;
}
/**
 * _strtok - splits a string into tokens
 * @str: pointer to the string to split
 * @delim: pointer to the string containing the delimiters
 * Return: a pointer to the next token, NULL if there are no more tokens
 */
char *_strtok(char *str, const char *delim)
{
	static char *buffer = NULL; // a buu/ffer to save the string
	char *token;
	int flag = 0;
	/**
	 * //first time call the function  put the string in the buffer
	 *remember that the buffer is static so it is initiazled once with NULL and it will not be destroyed
	 *after the function call and it will be used in the next call
	 */
	if (str != NULL) 
	{
		buffer = str;
	}
	if (buffer == NULL)
	{ 
		return NULL;
	}
	if (*buffer == '\0')
	{
		return NULL;
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
			return token;
		}
		else
		{
			buffer++;
		}
	}
	return token;
}
/**
 * _realloc - reallocates a memory block using malloc and free
 * @old_ptr: pointer to the memory previously allocated
 * @old_size: size, in bytes, of the allocated space for old_ptr
 * @new_size: new size, in bytes of the new memory block
 * Return: a pointer to the new allocated memory
 */
void *_realloc(void *old_ptr, size_t old_size, size_t new_size){
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
	{
		return (old_ptr);
	}
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
/**
 * _getline - reads an entire line from stream, storing the address of the buffer containing the text into *lineptr
 * @lineptr: pointer to the buffer containing the text
 * @n: size of the buffer
 * @stream: pointer to a FILE object that identifies an input stream
 * Return: the number of characters read, -1 if an error occurs or EOF is reached
 */
int _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *bufferPtr = NULL;
	char *positionChar = NULL;
	size_t sizeLine = 0; 
	int character;


	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return -1;
	}

	bufferPtr = *lineptr;
	sizeLine = *n;
	character = _getchar();

	if (character == EOF)
	{
		return -1;
	}

	if (bufferPtr == NULL) // allocatioing supace for the line in the buffer is set to null
	{
		bufferPtr = malloc(sizeof(char) * 1024);
		if (bufferPtr == NULL)
		{
			perror("malloc");
			return -1;
		}
		sizeLine = 1024;
	}
	positionChar = bufferPtr; // set the position of the char to first char in the line and store it in the buffer
							  // read a char till the end of the line store it in the buffer and move the position pointer to the next char
							  // if the char is a new line break the loop
							  //
	while (character != EOF)
	{
		// #elements = end - start + 1
		// allcoate more space if the size of the line is bigger than the size of the buffer
		if ((size_t)(positionChar - bufferPtr) > (sizeLine - 1))
		{
			sizeLine += 1024;
			bufferPtr = _realloc(bufferPtr, *n, sizeLine);
			if (bufferPtr == NULL)
			{
				perror("realloc");
				return -1;
			}
		}
		*positionChar++ = character; // save char in the buffer then move the position pointer to the next char
		if (character == '\n')
		{
			break;
		}
		character = fgetc(stream);
	}
	*positionChar++ = '\0';
	*lineptr = bufferPtr; // set the line pointer to the buffer remember the buffer is a pointer to the first char in the line
						  // and points to allocated space in the heap we must store it in the line pointer bcs
						  // when the function return this pointers we will have no access to the buffer
	*n = sizeLine;
	return positionChar - bufferPtr - 1; // -1 bcs we dont want to count the null byte
}
/**
 * _getenv - searches for the environment string pointed to by name and returns the associated value to the string
 * @name: pointer to the string containing the name of the environment variable
 * Return: a pointer to the value in the environment, NULL if the environment variable does not exist
 */
void print_env()
{
	extern char **environ;
	int i = 0;
	for (i = 0; environ[i] != NULL; i++)
	{
		_puts(environ[i]);
		_putchar('\n');
	}
}
/**
 * _getenv - searches for the environment string pointed to by name and returns the associated value to the string
 * @name: pointer to the string containing the name of the environment variable
 * Return: a pointer to the value in the environment, NULL if the environment variable does not exist
 */
char *get_command_path(char *command, size_t commandCount, int* code) {
	char *PATH = getenv("PATH"); // get the path variable
	char *paths = _strdup(PATH); // cpy the path variable to a string bcs we donot want to modify the original path variable
	char *path = _strtok(paths, ":"); // split the paths string into tokens bcs the dirs are seperated by :
	char *abs_path;
	*code = 0;
	// the code is 0 for null and 1 for abs path and 2 for relative path

	if (paths == NULL || path == NULL || command == NULL)
	{
		free(paths);
		paths = NULL;
		*code = 0;
		return NULL;
	}

	while (path != NULL)
	{
		abs_path = malloc(_strlen(path) + _strlen(command) + 2); // allocate space for the absolute path + 2 for / and \0 // rember the strlen stops at \0 so we will get the the right one
		if (abs_path == NULL)
		{
			perror("malloc");
			return NULL;
		}
		_strcpy(abs_path, path); // copy the path to abs_path
		_strcat(abs_path, "/");  // add /
		_strcat(abs_path, command); // append the command

		if (!access(abs_path, X_OK | F_OK))
		{
			free(paths);
			paths = NULL;
			*code = 1;
			return abs_path;
		}
		free(abs_path);
		abs_path = NULL;
		path = _strtok(NULL, ":");
	}

	free(paths);
	paths = NULL;

	if (access(command, X_OK | F_OK) == 0)
	{
		*code = 2;
		return command;
	}
	return NULL;
}
/**
 * exec_command - executes a command
 * @argv: pointer to an array of pointers to strings containing the arguments
 * @commandCount: the number of the command
 */
void exec_command(char **argv, size_t commandCount)
{
	pid_t pid;
	int status, code = 0;
	char *cmd_path;
	char *num;

	pid = fork();
	if (pid == -1) 
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		cmd_path = get_command_path(argv[0],commandCount, &code); // get the absolute path of the command

		if (cmd_path != NULL)
		{ // if the command is found
			argv[0] = cmd_path;
			/* if (execve(argv[0], argv, NULL) == -1) */
			/* { */
			/* 	free(cmd_path); */
			/* 	cmd_path = NULL; */
			/* 	perror("execve"); */
			/* 	exit(EXIT_FAILURE); */
			/* } */
			/* if (cmd_path != NULL) */
			/* { */
			/* 	free(cmd_path); */
			/* 	cmd_path = NULL; */
			/* } */
			if (code == 1)// if the command is found with abs_path which is dynamicly allocated
			{
				if (execve(argv[0], argv, NULL) == -1)
				{
					perror("execve");
					exit(EXIT_FAILURE);
				}
					free(cmd_path);
					cmd_path = NULL;
			}
			if (code == 2)// if the command is found with relative path which is not dynamicly allocated
			{
				if (execve(argv[0], argv, NULL) == -1)
				{
					perror("execve");
					exit(EXIT_FAILURE);
				}
			}

		} 
		else
		{
			num = num_to_string(commandCount);
			_puts("sh: ");
			_puts(num);
			_puts(": ");
			_puts(argv[0]);
			_puts(": not found\n");
			free(num);
			num = NULL;
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}
/**
 * main - the main function
 * @argc: the number of arguments
 * @argv: pointer to an array of pointers to strings containing the arguments
 * Return: 0 on success, -1 on failure
 */

int main(int argc, char **argv) 
{
	char *prompt = "($) ";
	char *line_ptr = NULL, *line_cpy = NULL, *token = NULL;
	const char *delim = " \t\n";
	size_t line_size = 0, n_chars_read = 0, num_tokens = 0, i = 0, commandCount = 0;

	(void)argc;
	while (1)
	{
		_puts(prompt);

		n_chars_read = 	_getline(&line_ptr, &line_size, stdin);
		if (n_chars_read == -1) 
		{
			perror("getline");
			return (-1);
		}

		line_cpy = _strdup(line_ptr);
		if (line_cpy == NULL)
		{
			perror("strdup");
			return (-1);
		}

		token = _strtok(line_ptr, delim);
		while (token != NULL)
		{
			num_tokens++;
			token = _strtok(NULL, delim);
		}

		argv = malloc(sizeof(char *) * (num_tokens + 1));/* +1 for NULL */
		if (argv == NULL)
		{
			perror("malloc");
			return (-1);
		}

		token = _strtok(line_cpy, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = _strdup(token);
			if (argv[i] == NULL)
			{
				perror("strdup");
				for (i--; (int)i >= 0; i--)
					free(argv[i]);
				free(argv);
			}
			token = _strtok(NULL, delim);
		}
		argv[i] = NULL;

		commandCount++;
		exec_command(argv, commandCount);

		for (i = 0; argv[i] != NULL; i++)
		{
			free(argv[i]);
			argv[i] = NULL;
		}
		free(argv);
		argv = NULL;
		free(line_ptr);
		line_ptr = NULL;
		free(line_cpy);	
		line_cpy = NULL;
	}

	return (0);
}


