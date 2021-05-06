#include "minishell.h"

void	create_empty_node(t_env *environ)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	line->origin_line = ft_strdup("");
	line->clone_line = NULL;
	environ->cli = ft_lst_new_lst(line);
}

void	insert_node_in_list(t_env *environ, t_lista *new)
{
	while (environ->cli->prev)
		environ->cli = environ->cli->prev;
	new->prev = environ->cli;
	if (environ->cli->next)
	{
		new->next = environ->cli->next;
		environ->cli->next->prev = new;
	}
	environ->cli->next = new;
}

void	create_node(t_env *environ)
{
	t_lista	*new;
	t_line	*line;
	t_line	*content;

	content = environ->cli->content;
	line = malloc(sizeof(t_line));
	if (!content->clone_line)
	{
		line->origin_line = ft_strdup(environ->cmd_buff);
		line->clone_line = NULL;
	}
	else
	{
		line->origin_line = ft_strdup(environ->cmd_buff);
		line->clone_line = NULL;
		content->clone_line = NULL;
	}
	new = ft_lst_new_lst(line);
	insert_node_in_list(environ, new);
}
