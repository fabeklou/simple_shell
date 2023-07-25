#include "hsh_main.h"

/**
 * main - entry point
 *
 * Description: creates a prompt that reads input, sep it,
 * executes and waits for another command unless exit is executed
 *
 * @ac: number of arguments
 * @av: array of string (tokens)
 * @env: environment variable
 *
 * Return: EXIT_SUCCESS (0) on success
 */
int main(int ac, char **av, char **env)
{
	char **args, **path, *line;
	int count = 0, status = 0;
	(void)av;
	(void)ac;

	signal(SIGINT, _handle_signal);

	while (1)
	{
		prompt();

		/* gets the user command */
		line = _read_input();

		/* splits string to get command and args */
		args = _sep_str(line, env);

		if ((_strcmp(args[0], "\n") != 0) && (_strcmp(args[0], "env") != 0))
		{
			count += 1;
			path = _search_path(env);

			status = _stat(args, path);
			_child_process(av, args, env, status, count);
		}
		else
		{
			free(args);
		}
		free(line);
	}

	return (EXIT_SUCCESS);
}
