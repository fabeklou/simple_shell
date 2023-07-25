#include "hsh_main.h"

/**
 * _child_process - executes a command if the given path is an executable file
 *
 * @args: the command to be executed
 * @env: environment variable
 * @stus_main: status variable
 * @av: name of the program
 * @cnt: number of prompt
 *
 * Return: 1
 */
int _child_process(char **av, char **args, char **env, int stus_main, int cnt)
{
	pid_t pid;
	int status;

	if (args == NULL)
		return (-1);

	pid = fork();

	if (pid < 0)
	{
		perror("./hsh: ");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			_error(av[0], cnt, args[0]);
			free(args);
			exit(1);
		}
		exit(0);
	}
	else
	{
		if (stus_main == 1)
			free(args[0]);

		free(args);
		waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}

/**
 * _search_path - gets the path to execute the command
 *
 * @environ: environment variable
 *
 * Return: the path tokens
 **/
char **_search_path(char **environ)
{
	char **token_path;
	int position = 0;

	for (; environ[position] != NULL; position++)
	{
		if (environ[position][0] == 'P' && environ[position][2] == 'T')
			token_path = _which(environ[position]);
	}

	return (token_path);
}

/**
 * _which - identifies the path of the given command
 *
 * @foundpath: the given command
 *
 * Return: the complete path of the command or 0 on failure
 */
char **_which(char *foundpath)
{
	int size = TOK_BUFSIZE, i = 0;
	char *copy_path = NULL, *tokens = NULL, *sparse = ":=";
	char **dir = _calloc(sizeof(char *), size);

	if (foundpath == NULL)
	{
		free(foundpath);
		return (0);
	}

	if (dir == NULL)
	{
		free(foundpath);
		perror("Error allocated memory");
		return (NULL);
	}

	copy_path = _strdup(foundpath);
	tokens = strtok(copy_path, sparse);

	while (tokens != NULL)
	{
		dir[i] = tokens;
		i++;
		tokens = strtok(NULL, sparse);
	}

	return (dir);
}
