#include "minishell.h"

int	cap_key_left(t_env *lst_env)
{	
	if (lst_env->cli_bufflen >= 1)
	{
		tputs(cursor_left, 1, ft_putchar);
		lst_env->cli_bufflen--;
		ft_bzero(lst_env->ch, sizeof(lst_env->ch));
		lst_env->check_esc = 0;
	}
	return (0);
}
