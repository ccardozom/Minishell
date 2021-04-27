#include "minishell.h"

t_line	*next_line_key(t_env *environ)
{
	if (*environ->cmd_buff)
	{
		create_node(environ);
	}
	environ->cmd_cursor = environ->cmd_buff;
	*environ->cmd_cursor = '\0';
	write(1, "\n", 1);
	while (environ->cli->prev)
		environ->cli = environ->cli->prev;
	return (environ->cli->next->content);
}
