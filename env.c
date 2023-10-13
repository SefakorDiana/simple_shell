#include "main.h"

/**
 * _env - builtin func to print whatever is
 * inside our enviroment variables
 *
 * @command:Contains informations
 * about the user command
 * Return: 0 for success and 1 for error
 */
int _env(command_t *command)
{
	char **iterator;

	(void)command;

	iterator = __environ;
	if (!iterator)
		return (1);
	while (*iterator)
	{
		_fprint(1, "%s\n", *iterator);
		iterator++;
	}
	return (0);
}
