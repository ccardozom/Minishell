#include "minishell.h"

t_line	*next_line_key(t_env *lst_env)
{
	if (*lst_env->cmd_buff)
	{
		create_node(lst_env);
		lst_env->cli_bufflen = 0;
		while (lst_env->cli->prev)
			lst_env->cli = lst_env->cli->prev;
	}	
	write(1, "\n", 1);
	if (lst_env->cli->next->content)
		return (lst_env->cli->next->content);
	else
		return (NULL);
}
