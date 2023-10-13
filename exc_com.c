#include "main.h"

/**
 * _exclude_comment - This func removes comments
 * from lines
 *
 * @line: full line that user entered
 * Return: A new line without comment
 */
char *_exclude_comment(const char *line)
{
	int comment_position;

	comment_position = _get_comment_position(line);
	return (_strslice(line, 0, comment_position));
}
