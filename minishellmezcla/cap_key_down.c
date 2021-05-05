#include "minishell.h"

int	cap_key_down(t_env *lst_env)
{
	if (lst_env->cli->prev)
	{
		lst_env->cli = lst_env->cli->prev;
		find_history(lst_env);
	}
	ft_bzero(lst_env->ch, sizeof(lst_env->ch));
	lst_env->check_esc = 0;
	return (0);
}
