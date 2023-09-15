#include "shell.h"


void execute(char **argv)
{
	char *command = NULL, *real_command = NULL;
	pid_t child_process;
	if (argv)
	{
		command = argv[0];
		real_command = get_location(command);
		if (real_command)
		{
			child_process = fork();
			if (child_process == 0)
			{	
				if (execve(real_command, argv, NULL) == -1)
					perror("execve_ error");
			}
			wait(NULL);
		}
	}
}
