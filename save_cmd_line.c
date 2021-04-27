#include "minishell.h"

void	create_empty_nodo(t_env *environ)
{
	t_line *line;

	line = malloc(sizeof(t_line));
	line->origin_line = ft_strdup("");
	line->clone_line = NULL;
	environ->cli = ft_lst_new_lst(line);
}

void	save_comand_line(t_env *environ)
{
	t_lista	*new;
	t_line *line;

	line = malloc(sizeof(t_line));
	line->origin_line = ft_strdup(environ->cmd_buff);
	line->clone_line = NULL;

	new = ft_lst_new_lst(line);
	new->prev = environ->cli;
	if (environ->cli->next)
	{
		new->next = environ->cli->next;
		environ->cli->next->prev = new;
	}
	environ->cli->next = new;
}

void	origin_clone_line(t_line *dst, char *str)
{
	dst->origin_line = ft_strdup(str);
}
void	save_comand_line_clone(t_env *environ)
{
	t_line *new_line;
	t_lista *lista;

	new_line = environ->cli->content;
	new_line->clone_line = ft_strdup(environ->cmd_buff);
	lista = ft_lst_new_lst(new_line);
	while (environ->cli->prev)
		environ->cli = environ->cli->prev;
	lista->prev = environ->cli;
	if (environ->cli->next)
	{
		lista->next = environ->cli->next;
		environ->cli->next->prev = lista;
	}
	environ->cli->next = lista;
}
