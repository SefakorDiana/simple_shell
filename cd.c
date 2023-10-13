#include "main.h"

/**
 * _cd_helper - A func helper of a cd
 * that takes key and look it up
 * in enviroments variable and change
 * directory to it
 *
 * @key: environment keys
 * Return: 0 as success and otherwise as error
 */
int _cd_helper(const char *key)
{
	char *s, buffer[200];

	getcwd(buffer, 200);
	s = _enviroment_management(GET_VALUE, key, NULL);
	if (chdir(s) == -1)
	{
		free(s);
		return (errno);
	}
	_enviroment_management(SET_ENTRY, "OLDPWD", buffer);
	free(s);
	return (0);
}

/**
 * _cd_helper2 - Takes
 * path as parameter and changes
 * directory to it
 *
 * @path: Changes directory to it's path
 * Return: 0 as success and otherwise as error
 */
int _cd_helper2(const char *path)
{
	char buffer[200];

	getcwd(buffer, 200);
	if (chdir(path) == -1)
	{
		perror(_global_states(GET_SHELL_NAME, NULL));
		return (errno);
	}
	_enviroment_management(SET_ENTRY, "OLDPWD", buffer);
	return (0);
}

/**
 * _cd - Allows for navigation
 * through out different
 * folders (directories) in our operating
 * system
 *
 * @command: struct the stored information
 * about passed commands
 * Return: 0 as success and otherwise as error
 */
int _cd(command_t *command)
{
	int len;

	len = _str2dlen(command->arguments + 1);

	if (len >= 1)
	{
		if (_strcmp("-", command->arguments[1]))
			return (_cd_helper("OLDPWD"));
		else if (_strcmp("~", command->arguments[1]))
			return (_cd_helper("HOME"));
		else
			return (_cd_helper2(command->arguments[1]));
	}
	else if (!len)
		return (_cd_helper("HOME"));
	return (0);
}
