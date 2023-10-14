#include "main.h"

/**
 * _handle_sigint - Handle the SIGINT signal (Ctrl+C)
 * @sig: The signal number (unused in this function).
 * Return: nothing
 */
void _handle_sigint(int sig)
{
	(void)sig;
	fflush(stdin);
	if (isatty(STDIN_FILENO))
	{
		_fprint(1, "\n%s> ",
				_global_states(GET_SHELL_NAME, NULL));
	}
}
