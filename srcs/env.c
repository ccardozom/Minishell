#include "../include/minishell.h"


void imprimirlista(t_list *cabeza)
{
	t_list *naux = cabeza;

	while (naux != NULL)
	{
		printf("%s \n", naux->content);
		naux = naux->next;
	}
}

void	capture_env(t_all *mini ,char **env)
{
	t_campo *datos;
	t_control *control;
	t_list	*lista;

	datos = NULL;
	datos = malloc(sizeof(t_campo));
	//printf("%lu \n",sizeof(t_campo));
	while (*env)
	{
		insertardatos(&datos, *env);
		/*if (!control->inicio)
			control->inicio = ft_lstnew(datos);
		else
			ft_lstadd_front(&lista, control->inicio);*/
		env++;
		printf("nombre = %s \n", datos->nombre);
		printf("valor = %s \n", datos->valor);
	}
	//imprimirlista(lista);
	
}