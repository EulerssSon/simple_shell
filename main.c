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
/*		printf("outside if %ld  len %ld string %s\n", nchars,strlen(line), line);*/
		if (nchars == -1)
		{
			exit(EXIT_SUCCESS);
		}
		if(line[0] == '\n' && nchars == 1)
		{
			printf("in newline \n");
			free(line);
			continue;
		}
		argv = tokenize(line);
		if (argv[0] == NULL)
		{
			free_2d(&argv);
			exit(EXIT_SUCCESS);
		}
		free(line);
	/*	for (i = 0; argv[i] != NULL; i++)*/
	/*		printf("args%s\n", argv[i]);*/
		exc_cmd(argv);
		free_2d(&argv);
			
	}
	return (0);
}
