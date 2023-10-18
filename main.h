#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <dirent.h>
#include <stdarg.h>
#define BUFFER_SIZE 1024
#define BACKET_SIZE 64

/**
 *struct entry_s -  Structure representing a
 *key-value pair for environment variables.
 *@key: The key (name) of the environment variable
 *@value:  The value associated with the environment variable.
 */
typedef struct entry_s
{
	char *key;
	char *value;
} entry_t;

/**
 * enum status_actions_e -  Enumeration of status-related actions
 * @UPDATE_STATUS: Action to update the status value.
 * @GET_STATUS: Action to retrieve the current status value.
 */
typedef enum status_actions_e
{
	UPDATE_STATUS,
	GET_STATUS
} status_actions_t;

/**
 * struct list_s - Structure representing a singly-linked list node.
 * @data: Data stored in the list node.
 * @next: Pointer to the next node in the list.
 */
typedef struct list_s
{
	void *data;
	struct list_s *next;
} list_t;

/**
 * enum command_type_e - Enumeration of command types.
 * @BUILTINS: Represents a built-in command.
 * @EXTERNAL: Represents an external (non-built-in) command.
 * @NOT_FOUND: Represents a command that is not found.
 */
typedef enum command_type_e
{
	BUILTINS,
	EXTERNAL,
	NOT_FOUND
} command_type_t;
/**
 * struct command_s - Structure representing a shell command.
 * @name: The name of the command or program to execute.
 * @arguments: An array of arguments for the command
 * @type: The type of the command
 * (built-in, external, or not found)
 */
typedef struct command_s
{
	char *name;
	char **arguments;
	command_type_t type;
} command_t;
/**
 * struct builtin_s -  Structure representing a built-in shell command.
 *
 * @name: The name of the built-in command.
 * @function:  A function pointer to the implementation
 * of the built-in command.
 *
 */
typedef struct builtin_s
{
	char name[30];
	int (*function)(command_t *command);
} builtin_t;

/**
 * enum builtin_actions_e - Enumeration of actions
 * related to built-in commands.
 * @GET_BUILTIN: Action to retrieve the function
 * pointer of a built-in command.
 * @SET_BUILTIN: Action to set and register a new built-in command
 */
typedef enum builtin_actions_e
{
	GET_BUILTIN,
	SET_BUILTIN
} builtin_actions_t;
/**
 * struct map_s - Structure representing a simple hash map
 * @backets:  An array of linked lists serving as buckets
 * for hash table storage.
 */
typedef struct map_s
{
	list_t *backets[BACKET_SIZE];
} map_t;

/**
 * enum enviroment_action_e - Enumeration of actions related
 * to environment management.
 * @INIT_ENV: Action to initialize the environment.
 * @SET_ENTRY: Action to set a key-value entry in the environment.
 * @GET_VALUE: Action to get the value associated with a key
 * from the environment.
 * @GET_KEYS: Action to get a list of keys from the environment
 * @CONVERT_INTO_2D: Action to convert the environment
 * into a 2D array.
 * @CLEAR_ENV: Action to clear and reset the environment.
 * @DELETE_ENTRY: Action to delete an entry (key-value pair)
 * from the environment.
 */
typedef enum enviroment_action_e
{
	INIT_ENV,
	SET_ENTRY,
	GET_VALUE,
	GET_KEYS,
	DELETE_ENTRY,
	CONVERT_INTO_2D,
	CLEAR_ENV
} enviroment_action_t;

/**
 * enum globals_action_e - Enumeration of actions related to
 * global shell variables.
 * @GET_LINE: Action to retrieve the current command line.
 * @GET_LINE_NUMBER: Action to retrieve the current line number.
 * @GET_SHELL_NAME: Action to retrieve the shell's name
 * @SET_LINE: Action to set the current command line.
 * @SET_SHELL_NAME: Action to set the shell's name.
 * @INCREMENT_LINE_NUMBER: Action to increment the current line number
 * @SET_2D: set a 2D array.
 * @GET_2D: to retrieve a 2D array.
 */
typedef enum globals_action_e
{
	GET_LINE,
	GET_LINE_NUMBER,
	GET_SHELL_NAME,
	SET_LINE,
	SET_SHELL_NAME,
	INCREMENT_LINE_NUMBER,
	SET_2D,
	GET_2D
} globals_action_t;

typedef int (*builtins_t)(command_t *);

char *_copy(char *dest, const char *src, size_t size);
void *_realloc(void *old_buffer, size_t old_size, size_t new_size);
ssize_t _getline(char **line);
char *_trim_white_space(const char *line);
int _parsing_error_handler(char *line);
size_t _strlen(const char *s);
void _free_split(char ***backets);
char **_split(const char *line, const char *diameter);
list_t *add_to_list(list_t **lst, void *data);
void *pop_from_list(list_t **list);
size_t _listlen(const list_t *list);
void free_list(list_t *list, void (*free_content)(void *data));
int _strcmp(const char *str1, const char *str2);
char *_strdup(const char *str);
int _get_hash_code(const char *key);
map_t *_init_map(void);
int _set_value(map_t *map, const char *key, const char *value);
char *_get_value(const map_t *map, const char *key);
void _clear_entry(void *data);
void _clear_map(map_t *map);
list_t *_get_keys(const map_t *map);
int _delete_entry(map_t *map, const char *key);
command_t *_init_command(char **tokens);
void _free_command(void *data);
command_t *_handle_command(const char *line);
int _semicolon_handler(const char *line);
list_t *_pipe_handler(const char *line);
int _handle_pipe_execution(list_t *pipes, int previous_stdin);
int _status_management(status_actions_t action, int new_status);
void _handle_sigint(int sig);
void *_enviroment_management(enviroment_action_t action,
							 const char *key, const char *value);
int _status_management(status_actions_t action, int new_status);
char **_convert_env_into_2d_array(void);
void _feed_enviroment_variable(char **new_env);
char *_get_command_from_path(char *command);
char *_strslice(const char *line, int start, int end);
char *_strcat(const char *str1, const char *str2);
char *_itoa(int number);
char *_evaluate_enviroment_variable(char *env_key);
char **_trim_2darray(char **arr);
int _env(command_t *command);
int _isdigit(const char *s);
int _str2dlen(char **arr2d);
int _atoi(const char *str);
int __exit(command_t *command);
builtins_t _builtin_management(builtin_actions_t action, char *name,
							   int (*function)(command_t *command));
void _excute(command_t *command);
int _setenv(command_t *command);
int _unsetenv(command_t *command);
int _fprint(int fd, const char *format, ...);
void *_global_states(globals_action_t action, char **s);
int _cd(command_t *command);
void _handle_sigint(int sig);
void _prompt(void);
int _get_comment_position(const char *line);
char *_exclude_comment(const char *line);
#endif
