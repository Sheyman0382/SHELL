#include "shell.h"

/**
 * main - entry point
 *
 * Return: An integer
 */

int main(int argc, char **argv)
{
	char *command = NULL, *command_copy = NULL, *token;
	int command_length, i, token_count = 0;
	char *delim = " \n";
	ssize_t lineptr;
	size_t n = 0;

	(void)argc;

	while (1)
	{
		_printf("oluwaseyi@ALX_AFRICA$$ ");
		lineptr = getline(&command, &n, stdin);
		if (lineptr == -1)
		{
			_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		
		//we need to make a copy of the command read from the input user
		//this is because the command entered has to be tokenized with the strtok function
		//therefore memory needs to be dynamically allocated for the command_copy.
		command_copy = malloc(sizeof(char) * lineptr);
		if (command_copy == NULL)
		{
			perror("malloc error");
			return (-1);
		}

		strcpy(command_copy, command);
	

		token = strtok(command_copy, delim);
		while (token)
		{
			token_count++;
			token = strtok(NULL, delim);
		}
		argv = malloc(sizeof(char *) * token_count);
		if (argv == NULL)
		{
			perror("malloc error");
			return (-1);
		}
		token = strtok(command, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			if (argv[i] == NULL)
			{
				perror("arv[i] error");
				return (-1);
			}
			else
			{
				strcpy(argv[i], token);
				token = strtok(NULL, delim);
			}
		}
		argv[i] = NULL;

		if (strcmp(argv[0], "exit") == 0)
		{
			exit(EXIT_SUCCESS);
		}
		
		if (strcmp(argv[0], "env") == 0)
		{
			environ_var();
		}
		execute(argv);

		free (command_copy);
		while (token_count != 0)
		{
			free (argv[token_count]);
			token_count--;
		}
		free (argv);
	}
	return (0);
}
