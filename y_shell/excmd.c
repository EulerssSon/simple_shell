#include "main.h"


void exc_cmd (char **argv)
{
	pid_t pid = fork();
	int status;

	/*cmd = get_loc(cmd);*/
	if (pid == -1)
	{
		perror("error in fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if(execve(argv[0], argv, NULL)== -1)
		{
			perror("execution error");
			exit (EXIT_FAILURE);
		}
	}
	if (pid > 0)
	{
		wait(&status);
	}
}
