#include "main.h"

/**
 * _unsetenv - Unset an environment variable.
 * @command: The command structure containing arguments.
 * Return:  0 on success, 1 on failure
 */
int _unsetenv(command_t *command)
{
	int car;

	car = _str2dlen(command->arguments);
	if (car != 2)
	{
		_fprint(2, "%s: Invalid number of arguments\n",
				_global_states(GET_SHELL_NAME, NULL));
		return (1);
	}
	_enviroment_management(DELETE_ENTRY, command->arguments[1], NULL);
	return (0);
}
