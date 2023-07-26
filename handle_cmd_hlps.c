#include "hsh_main.h"

/**
 * prompt - prints the prompt '$' and waits for a user's input
 *
 * Return: nothing
 */
void prompt(void)
{
	char *prompt = {"$ "};
	char *buffer = getcwd(NULL, 0);

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
	}
	free(buffer);
}

/**
 * _read_input - stores whatever is passed to it as standard input
 *
 * Return: string containing the input
 */
char *_read_input(void)
{
	char *line = NULL;
	ssize_t signal;
	size_t bufsize = 0;
	int i;

	signal = getline(&line, &bufsize, stdin);

	if (!line)
	{
		perror("Error allocating memory for buffer");
		return (0);
	}

	if (signal == 1)
	{
		free(line);
		return (NULL);
	}
	else if (signal == EOF)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(line);
		exit(0);
	}
	else
	{
		for (i = 0; line[i] == ' ' && line[i + 1] == ' '; i++)
			;
		if (!line[i] && line[i + 1] == '\n')
		{
			free(line);
			return (0);
		}
	}

	return (line);
}

/**
 * _sep_str - devides a long string into and array of words
 *
 * @line: the string to be devided
 * @env: environment variable
 *
 * Return: tokens (array of strings) on succes or EXIT_FAILURE otherwise
 */
char **_sep_str(char *line, char **env)
{
	int bufsize = TOK_BUFSIZE, position = 0;
	char *token, **tokens;

	if (line == NULL)
		return (0);

	tokens = _calloc(sizeof(char *), bufsize);

	if (!tokens)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, TOK_DELIM);

	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		token = strtok(NULL, TOK_DELIM);
	}

	if (tokens[0] == NULL)
		tokens[position] = "\n";

	if ((_strcmp(tokens[0], "exit") == 0) && tokens[1] == NULL)
	{
		free(line);
		free(tokens);
		exit(0);
	}

	if ((_strcmp(tokens[0], "env") == 0) && tokens[1] == NULL)
		_printenv(env);

	return (tokens);
}
