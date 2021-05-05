#include "minishell.h"

void	create_empty_nodo(t_env *lst_env)
{
	t_line *line;

	line = malloc(sizeof(t_line));
	
	ft_bzero(line->origin_line, 2048);
	ft_bzero(line->clone_line, 2048);
	lst_env->cli = ft_lst_new_lst(line);
}

void	save_comand_line(t_env *lst_env)
{
	t_lista	*new;
	t_line *line;

	line = malloc(sizeof(t_line));
	ft_strlcpy(line->origin_line, lst_env->cmd_buff, ft_strlen(lst_env->cmd_buff) + 1);
	ft_bzero(line->clone_line, 2048);

	new = ft_lst_new_lst(line);
	new->prev = lst_env->cli;
	if (lst_env->cli->next)
	{
		new->next = lst_env->cli->next;
		lst_env->cli->next->prev = new;
	}
	lst_env->cli->next = new;
}

void	origin_clone_line(t_line *dst, char *str)
{
	ft_strlcpy(dst->origin_line, str, ft_strlen(str) + 1);
void	save_comand_line_clone(t_env *lst_env)
{
	t_line *new_line;
	t_lista *lista;

	new_line = lst_env->cli->content;
	ft_strlcpy(new_line->clone_line, lst_env->cmd_buff, ft_strlen(lst_env->cmd_buff) + 1);
	lista = ft_lst_new_lst(new_line);
	while (lst_env->cli->prev)
		lst_env->cli = lst_env->cli->prev;
	lista->prev = lst_env->cli;
	if (lst_env->cli->next)
	{
		lista->next = lst_env->cli->next;
		lst_env->cli->next->prev = lista;
	}
	lst_env->cli->next = lista;
}
