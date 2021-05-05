#include "minishell.h"

void	create_empty_node(t_env *lst_env)
{
	t_line *line;

	line = malloc(sizeof(t_line));
	printf("memoria para liberar en empty-node: %p\n", line);
	ft_bzero(line->origin_line, 2048);
	//line->origin_line = ft_strdup("");
	printf("memoria para liberar en empty-node: %p\n", line->origin_line);
	//line->clone_line = NULL;
	ft_bzero(line->clone_line, 2048);
	lst_env->cli = ft_lst_new_lst(line);
}

void	insert_node_in_list(t_env *lst_env, t_lista *new)
{
	while (lst_env->cli->prev)
		lst_env->cli = lst_env->cli->prev;
	new->prev = lst_env->cli;
	if (lst_env->cli->next)
	{
		new->next = lst_env->cli->next;
		lst_env->cli->next->prev = new;
	}
	lst_env->cli->next = new;
}

void	create_node(t_env *lst_env)
{
	t_lista	*new;
	t_line *line;
	t_line *content;

	content = lst_env->cli->content;
	line = malloc(sizeof(t_line));
	if (!(*content->clone_line))
	{
		ft_strlcpy(line->origin_line, lst_env->cmd_buff, ft_strlen(lst_env->cmd_buff) + 1);
		ft_bzero(line->clone_line, 2048);
	}
	else
	{
		ft_strlcpy(line->origin_line, lst_env->cmd_buff, ft_strlen(lst_env->cmd_buff) + 1);
		ft_bzero(line->clone_line, 2048);
		ft_bzero(content->clone_line, 2048);
	}
	new = ft_lst_new_lst(line);
	insert_node_in_list(lst_env, new);
}
