#include "main.h"

/**
 * _free_command - This is a func that frees command
 *
 * @data: freed data
 * Return: Nothing
 */
void _free_command(void *data)
{
	command_t *cmd;

	cmd = data;
	_free_split(&cmd->arguments);
	free(data);
}

/**
 * _lookup_for_command - This func searches
 * for a given command on the builtins
 * as well as in the path
 *
 * @command: to be lookedup
 * @type: type of command
 * Return: correct path or command if it's builtin
 */
char *_lookup_for_command(char *command, command_type_t *type)
{

	if (_builtin_management(GET_BUILTIN, command, NULL))
	{
		*type = BUILTINS;
		return (_strdup(command));
	}

	return (_get_command_from_path(command));
}
/**
 * _init_command - This func initializes commands
 *
 * @tokens: A 2d array that holds all command arguments
 * and contains the name of the command in the first argument
 * Return: command to be allocated
 */
command_t *_init_command(char **tokens)
{
	command_t *command;
	struct stat st;
	char *scommand;

	command = malloc(sizeof(command_t));
	if (!command)
		return (NULL);
	command->type = NOT_FOUND;
	scommand = _lookup_for_command(tokens[0], &command->type);
	free(tokens[0]);
	tokens[0] = scommand;
	if (command->type == NOT_FOUND &&
		(tokens[0][0] == '.' || tokens[0][0] == '/') &&
		!stat(tokens[0], &st))
		command->type = EXTERNAL;
	command->arguments = tokens;
	command->name = tokens[0];
	return (command);
}
/**
 * _handle_command - Takes a line
 * and turns it into an easy command to be
 * work with
 *
 * @line: to be parsed
 * Return: A well structured method
 */
command_t *_handle_command(const char *line)
{
	char *trimmed_line, *command_name;
	char **tokens[2];
	int iterator;

	trimmed_line = _trim_white_space(line);
	tokens[0] = _split(trimmed_line, " ");
	free(trimmed_line);
	if (!tokens[0])
		return (NULL);
	iterator = 0;
	while (tokens[0][iterator])
	{
		if (tokens[0][iterator][0] == '$')
		{
			command_name = _evaluate_enviroment_variable(tokens[0][iterator] + 1);
			free(tokens[0][iterator]);
			if (command_name)
				tokens[0][iterator] = command_name;
			else
				tokens[0][iterator] = _strdup("");
		}
		iterator++;
	}
	tokens[1] = _trim_2darray(tokens[0]);
	_free_split(&tokens[0]);
	return (_init_command(tokens[1]));
}
