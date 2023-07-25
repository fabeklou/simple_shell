#include "hsh_main.h"

/**
 * _printenv - prints the current environment
 *
 * @environ: environment variable
 */
void _printenv(char **environ)
{
	int i = 0;

	for (; environ[i]; i++)
		_puts(environ[i]);
}
