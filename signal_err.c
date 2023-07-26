#include "hsh_main.h"

/**
 * _handle_signal - prints the prompt
 *
 * @signal: the signal
 *
 * Return: nothing
 */
void _handle_signal(int signal)
{
	char *prompt = {"\n$ "};
	(void)signal;

	write(STDOUT_FILENO, prompt, _strlen(prompt));
	fflush(stdout);
}

/**
 * _stat - gets information about a file
 *
 * @cmd: pointo with commands
 * @path: location of each directory
 *
 * Return: on success, zero is returned. On error, -1 is returned,
 * and errno is set appropriately
 **/
int _stat(char **cmd, char **path)
{
	char *conc_str = NULL, *new_concat = NULL;
	int count;
	struct stat sb;

	if (path == NULL)
	{
		free(path);
		free(cmd);
		return (0);
	}

	for (count = 0; path[count] != NULL; count++)
	{
		conc_str = str_concat(path[count], "/");
		new_concat = str_concat(conc_str, cmd[0]);
		if (stat(new_concat, &sb) == 0 && (sb.st_mode & S_IXUSR))
		{
			cmd[0] = new_concat;
			free(conc_str);
			free(path[0]);
			free(path);
			return (1);
		}
		free(conc_str);
		free(new_concat);
	}
	free(path[0]);
	free(path);
	return (0);
}

/**
 * _error - prints the error output of a file
 *
 * @argv: the name of the program
 * @count: total number of prompt
 * @args: failed command
 *
 * Return: 0 on success
 */
int *_error(char *argv, int count, char *args)
{
	char *number;

	number = _itoa(count, 10);

	write(STDERR_FILENO, argv, _strlen(argv));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, number, _strlen(number));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, args, _strlen(args));
	perror(" ");

	return (0);
}
