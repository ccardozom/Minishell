#include "minishell.h"

t_line	*next_line_key(t_env *environ)
{
	if (*environ->cmd_buff)
	{
		create_node(environ);
	}
	write(1, "\n", 1);
	while (environ->cli->prev)
		environ->cli = environ->cli->prev;
	return (environ->cli->next->content);
}
