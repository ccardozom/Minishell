#include "minishell.h"

int	capture(t_env *environ, char **env)
{
	int	index;

	index = 0;
	environ->lst = NULL;
	while (*env)
	{
		ft_insert_nodo_fin(&environ->lst, ft_lst_new_lst(array_to_var(*env)));
		env++;
		index++;
	}
	return (0);
}
//esto se puede cerrar como bueno
// hay que modificar los argunmentos que recibe la funcion capture
