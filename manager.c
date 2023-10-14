#include "main.h"

/**
 * _status_management - Manage and retrieve the current status of the shell.
 * @action: The action to perform on the shell status.
 * @new_status: The new status value to set
 * (only applicable when action is UPDATE_STATUS).
 * Return:  The current shell status if action is GET_STATUS
 * or 0 if action is UPDATE_STATUS.
 */

int _status_management(status_actions_t action, int new_status)
{
	static int status;

	if (action == UPDATE_STATUS)
		status = new_status;
	return (status);
}

/**
 * _enviroment_management - Manage environment variables within a map.
 * @action: The action to perform on environment variables.
 * @key: The key associated with the environment variable
 * @value: The value to set or retrieve
 * Return: A result or data based on the specified action
 */
void *_enviroment_management(enviroment_action_t action,
							 const char *key, const char *value)
{
	static map_t *map;

	if (action == INIT_ENV)
		map = _init_map();
	else if (action == SET_ENTRY)
		_set_value(map, key, value);
	else if (action == GET_VALUE)
		return (_strdup(_get_value(map, key)));
	else if (action == GET_KEYS)
		return (_get_keys(map));
	else if (action == CONVERT_INTO_2D)
		return (_convert_env_into_2d_array());
	else if (action == CLEAR_ENV)
		_clear_map(map);
	else if (action == DELETE_ENTRY)
		_delete_entry(map, key);
	return (NULL);
}

/**
 * _builtin_management -  Manage built-in commands and
 * their associated functions.
 * @action: The action to perform on built-in commands.
 * @name: The name of the built-in command
 * @function: A function pointer to the associated function
 * Return:  The function pointer associated with the specified
 * built-in command when action is GET_BUILTIN,
 * or NULL when action is SET_BUILTIN.
 */
builtins_t _builtin_management(builtin_actions_t action, char *name,
							   int (*function)(command_t *command))
{
	static builtin_t builtins[10];
	static int size;
	int iter;

	if (action == GET_BUILTIN)
	{
		iter = 0;
		while (iter < size)
		{
			if (_strcmp(builtins[iter].name, name))
				return (builtins[iter].function);
			iter++;
		}
	}
	if (action == SET_BUILTIN)
	{
		_copy(builtins[size].name, name, _strlen(name));
		builtins[size].function = function;
		size++;
	}
	return (NULL);
}

/**
 * _global_states - Manage global variables and their states.
 * @action: The action to perform on global variables.
 * @s:  Additional data or parameters based on the specified action.
 * Return: nothing
 */
void *_global_states(globals_action_t action, char **s)
{
	static char *line, *shell_name, **array_2d;
	static int line_number;

	if (action == SET_LINE)
		line = *s;
	if (action == SET_SHELL_NAME)
		shell_name = *s;
	if (action == GET_LINE)
		return (line);
	if (action == GET_SHELL_NAME)
		return (shell_name);
	if (action == GET_LINE_NUMBER)
		return (&line_number);
	if (action == INCREMENT_LINE_NUMBER)
		line_number++;
	if (action == SET_2D)
		array_2d = s;
	if (action == GET_2D)
		return (array_2d);
	return (NULL);
}
