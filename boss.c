#include "main.h"

/**
 * main - Entry point for a custom shell program.
 * @ac: The number of command-line arguments
 * @av: An array of strings representing the command-line arguments
 * Return: if successful 0, if not then error
 */
int main(int ac, char *av[])
{
	char *rope, *speech;

	(void)ac;
	signal(SIGINT, _handle_sigint);
	_enviroment_management(INIT_ENV, NULL, NULL);
	_feed_enviroment_variable(__environ);
	_builtin_management(SET_BUILTIN, "exit", __exit);
	_builtin_management(SET_BUILTIN, "env", _env);
	_builtin_management(SET_BUILTIN, "setenv", _setenv);
	_builtin_management(SET_BUILTIN, "unsetenv", _unsetenv);
	_builtin_management(SET_BUILTIN, "cd", _cd);
	_global_states(SET_SHELL_NAME, &av[0]);
	while (1)
	{
		_prompt();
		_getline(&rope);
		if (!rope)
		{
			free(rope);
			break;
		}
		speech = _trim_white_space(rope);
		free(rope);
		rope = speech;
		speech = _exclude_comment(rope);
		free(rope);
		rope = speech;
		_global_states(SET_LINE, &rope);
		_global_states(INCREMENT_LINE_NUMBER, NULL);
		_semicolon_handler(rope);
		free(rope);
	}
	_enviroment_management(CLEAR_ENV, NULL, NULL);
	return (_status_management(GET_STATUS, 0));
}
