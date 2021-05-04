#include "minishell.h"

t_line	*next_line_key(t_env *environ)
{
	if (*environ->cmd_buff)
	{
		create_node(environ);
	}
	ft_bzero(environ->cmd_buff, 2048);
	ft_bzero(environ->cmd_cursor, 2048);
	write(1, "\n", 1);
	while (environ->cli->prev)
		environ->cli = environ->cli->prev;
	return (environ->cli->next->content);
}
