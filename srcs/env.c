#include "../include/minishell.h"

void	capture_env(t_all *mini ,char **env)
{

	t_env *nuevo;
	t_env *renuevo;
	int i=0,cont=0;
	/*void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!alst)
		*alst = ft_lstnew((void *)new);
	else
	{
		new->next = *alst;
		*alst = new;
	}
}*/

	nuevo = malloc(sizeof(t_env));
	i = strlen(*env);
	while(cont < i)
	{
		//nuevo = malloc(sizeof(t_env));
		if (!nuevo->string)
		{	
			nuevo->string = env[cont];
			nuevo->next = NULL;
			nuevo->prev = NULL;
		}
		else
		{
			renuevo = malloc(sizeof(t_env));
			nuevo->next = renuevo->prev;
			renuevo->string = env[cont];
			nuevo = renuevo;
		}
		//printf("cadena = %s\n", nuevo->string);
		cont++;
	}
	while (nuevo->prev)
	{
		printf("cadena = %s\n",nuevo->string);
		nuevo = nuevo->next;
	}
	//nuevo = nuevo->next;
	//mini->start = nuevo;
	//printf("El valor añadido a la lista es = %s", nuevo->string);
}