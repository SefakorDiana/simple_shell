#include "main.h"

/**
 * _setenv - Set an environment variable to a specified value
 * @command: A pointer to a command structure containing arguments
 * Return:  0 if the environment variable is set successfully, 1 for error
 */
int _setenv(command_t *command)
{
	int fet;

	fet = _str2dlen(command->arguments + 1);
	if (fet != 2)
	{
		_fprint(2, "%s: Invalid number of arguments\n",
				_global_states(GET_SHELL_NAME, NULL));
		return (1);
	}
	_enviroment_management(
		SET_ENTRY,
		command->arguments[1],
		command->arguments[2]);
	return (0);
}
