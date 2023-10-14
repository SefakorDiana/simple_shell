#include "main.h"

/**
 * _prompt - Display a prompt for the user, if applicable.
 * Return: Nothing
 */
void _prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		_fprint(1, "%s> ",
				_global_states(GET_SHELL_NAME, NULL));
	}
}
