#include "shell.h"



void environ_var(void)
{
	extern char **environ;
	// Retrieve the environment variables and their values
	//environ variable is a global variable that can be accessed from
	//any file with the keyword "extern"
	char **env_var = environ;

	// Print the environment variables
	while (*env_var != NULL) 
	{
		puts(*env_var);
		env_var++;
	}
}

