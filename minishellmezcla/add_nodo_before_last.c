#include "minishell.h"

//recibe una lista y un string
//si existe el caracter = en el string agrega un nodo 
//en la penultima posicion de la lista

void	add_nodo_before_last(t_lista *lst, char *str)
{
	t_lista	*lista;
	t_lista	*aux;

	aux = lst;
	while (aux->next != NULL)
		aux = aux->next;
	while (*str != ' ')
		str++;
	str++;
	if (ft_strchr(str, '='))
	{
		lista = ft_lst_new_lst(array_to_var(str));
		lista->next = aux;
		lista->prev = aux->prev;
		aux->prev->next = lista;
		aux->prev = lista;
	}
}
