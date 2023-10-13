#include "main.h"

/**
 * _get_command_from_path - Takes command and
 * returns it's corresponding path
 *
 * @command: lookup for it's path
 * Return: path where command located
 */
char *_get_command_from_path(char *command)
{
	char *proper_command, *path,
		**path_2d, **iterator;
	struct stat st;

	if ((command[0] == '.' || command[0] == '/') &&
		!stat(command, &st))
		return (_strdup(command));
	path = _enviroment_management(GET_VALUE, "PATH", NULL);
	if (!path)
		return (_strdup(command));
	iterator = path_2d = _split(path, ":");
	free(path);
	while (*iterator)
	{
		path = _strcat(*iterator, "/");
		proper_command = _strcat(path, command);
		free(path);
		if (!stat(proper_command, &st))
		{
			_free_split(&path_2d);
			return (proper_command);
		}
		free(proper_command);
		iterator++;
	}
	_free_split(&path_2d);
	return (_strdup(command));
