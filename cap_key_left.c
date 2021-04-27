#include "minishell.h"

int	cap_key_left(t_env *environ)
{
	tputs(cursor_left, 1, ft_putchar);
	environ->cli_bufflen--;
	ft_bzero(environ->ch, sizeof(environ->ch));
	environ->check_esc = 0;
	return (0);
}
