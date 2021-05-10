#include "minishell.h"

int	set_env_delete(char *str, t_lista *lst)
{
	t_var	*var;
	t_lista	*aux;

	while (lst)
	{
		var = lst->content;
		if (strcmp(str, var->name) == 0)
		{
			if (lst->next)
			{
				aux = lst;
				lst->prev->next = lst->next;
				lst->next->prev = lst->prev;
				free(aux);
			}
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}

int	ft_delete_node(t_lista *lst, char *str)
{
	set_env_delete(str, lst);
	return (0);
}
