#include "minishell.h"

int	cap_key_right(t_env *environ)
{
	if (environ->cli_bufflen <= ft_strlen(environ->cmd_buff))
	{
		tputs(cursor_right, 1, ft_putchar);
		environ->cli_bufflen++;
		ft_bzero(environ->ch, sizeof(environ->ch));
		environ->check_esc = 0;
	}
	return (0);
}
