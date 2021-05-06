#include "minishell.h"

int	cap_key_down(t_env *environ)
{
	if (environ->cli->prev)
	{
		environ->cli = environ->cli->prev;
		find_history(environ);
	}
	ft_bzero(environ->ch, sizeof(environ->ch));
	environ->check_esc = 0;
	return (0);
}
