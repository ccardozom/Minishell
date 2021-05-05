#include "minishell.h"

int	capture(t_env *lst_env, char **env)
{
	int	index;

	index = 0;
	lst_env->lst = NULL;
	while (*env)
	{
		ft_insert_nodo_fin(&lst_env->lst, ft_lst_new_lst(array_to_var(*env)));
		env++;
		index++;
	}
	return (0);
}
