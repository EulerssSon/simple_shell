#include "main.h"


int main (int argc, char **argv)
{
/*	int i;*/
	char *prompt = "($) ", *line = NULL;
	size_t  n=0;
	ssize_t nchars;
	(void) argc;

	while(1)
	{
		if(isatty(STDIN_FILENO))
		{
			printf("%s", prompt);
			fflush(stdout);
		}
		nchars = getline(&line, &n, stdin);
		if (nchars == -1)
		{
		/*	printf("line %d\n",_strlen(line));*/
			free(line);
			exit(EXIT_SUCCESS);
		}
		if(line[0] == '\n' && nchars == 1)
		{
			free(line);
			continue;
		}
		argv = tokenize(line);
		if (argv[0] == NULL)
		{
			free(line);
			free_2d(&argv);
			exit(EXIT_SUCCESS);
		}
	/*	for (i = 0; argv[i] != NULL; i++)*/
	/*		printf("args%s\n", argv[i]);*/
		exc_cmd(argv);
			

	}
	free(line);
	free_2d(&argv);

	return (0);
}
