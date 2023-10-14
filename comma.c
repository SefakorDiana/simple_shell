#include "main.h"

/**
 * _execution_handler - Handle the execution of a command
 * @command: A pointer to a command structure containing command information.
 * Return: void
 */
void _execution_handler(command_t *command)
{
	if (access(command->name, F_OK | X_OK) != -1)
		_excute(command);
	else
	{
		_fprint(2, "%s: %d: %s: Permission denied\n",
				(char *)_global_states(GET_SHELL_NAME, NULL),
				*((int *)_global_states(GET_LINE_NUMBER, NULL)),
				command->name);
		_status_management(UPDATE_STATUS, 126);
	}
}
/**
 * _semicolon_handler -  Handle multiple commands separated by semicolons.
 * @line: A string containing one or more commands separated by semicolons.
 * Return: 1 if all commands were executed successfully
 * 0 if a memory allocation error occurred during command splitting.
 */
int _semicolon_handler(const char *line)
{
	char **semi_commands, **iterator;
	command_t *command;
	int argument_length;

	iterator = semi_commands = _split(line, ";");
	if (!iterator)
		return (1);
	while (*iterator)
	{
		command = _handle_command(*iterator);
		if (command->type == NOT_FOUND)
		{
			_fprint(2, "%s: %d: %s: not found\n",
					(char *)_global_states(GET_SHELL_NAME, NULL),
					*((int *)_global_states(GET_LINE_NUMBER, NULL)),
					command->name);
			_status_management(UPDATE_STATUS, 127);
		}
		else if (command->type == EXTERNAL)
			_execution_handler(command);
		else
		{
			_global_states(SET_2D, semi_commands);
			_status_management(UPDATE_STATUS,
							   _builtin_management(
								   GET_BUILTIN,
								   command->name, NULL)(command));
		}
		argument_length = _str2dlen(command->arguments);
		_enviroment_management(SET_ENTRY, "_",
							   command->arguments[argument_length - 1]);
		_free_command(command);
		iterator++;
	}
	_free_split(&semi_commands);
	return (0);
}
