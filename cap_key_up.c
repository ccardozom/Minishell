#include "minishell.h"

int	cap_key_up(t_env *environ)
{
	t_line *line;
	if (environ->cli->next)
	{
		environ->cli = environ->cli->next;
	line = environ->cli->content;
		find_history(environ);
	}
	ft_bzero(environ->ch, sizeof(environ->ch));
	environ->check_esc = 0;
	return (0);
}
