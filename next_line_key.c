#include "minishell.h"

char	*next_line_key(t_env *environ)
{
	t_line *line;
	//char	*cmd;

	//cmd = NULL;
	// si hay historial
//	{
	//	cmd = environ->cmd_buff;
//	}
	// si o hay historial
	line = environ->cli->content;
	printf("str: %s\n", line->origin_line);
	if (line->origin_line)
		save_comand_line_clone(environ);
	else if (*environ->cmd_buff)
		save_comand_line(environ);
	//{
	//	cmd = environ->cmd_buff;
	//}
	//else if (!*environ->cmd_buff)
	//	cmd = environ->cmd_buff;
	write(1, "\n", 1);
	environ->cmd_cursor = environ->cmd_buff;
	*environ->cmd_cursor = '\0';
	while (environ->cli->prev)
		environ->cli = environ->cli->prev;
	return (environ->cmd_buff);
}