#include "../include/minishell.h"

void	insertardatos(t_campo **datos, char *str)
{
	t_campo	*new;
	char	*aux;
	int		index;
	

	new = (t_campo *)malloc(sizeof(t_campo));
	index = 0;
	aux = ft_strchr(str, '=');
	aux++;
	new->valor = ft_strdup(aux);
	while (str[index] != '=')
		index++;
	new->nombre = ft_strndup(str, index);
	(*datos)->nombre = new->nombre;
	(*datos)->valor = new->valor;
}