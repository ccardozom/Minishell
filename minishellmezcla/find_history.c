#include "minishell.h"

void	find_history(t_env *lst_env)
{
	t_line	*line;

	line = lst_env->cli->content;
	tputs(restore_cursor, 1, ft_putchar);
	tputs(tgetstr("ed", 0), 1, ft_putchar);
	tputs(tgetstr("ce", 0), 1, ft_putchar);
	if (*line->clone_line)
	{
		ft_strcpy(lst_env->cmd_buff, line->clone_line);
		lst_env->cli_bufflen = ft_strlen(line->clone_line);
		lst_env->cmd_cursor = lst_env->cmd_buff + lst_env->cli_bufflen;
		ft_putstr_fd(line->clone_line, 1);
	}
	else if (*line->origin_line)
	{
		ft_strcpy(lst_env->cmd_buff, line->origin_line);
		lst_env->cli_bufflen = ft_strlen(line->origin_line);
		lst_env->cmd_cursor = lst_env->cmd_buff + lst_env->cli_bufflen;
		ft_putstr_fd(line->origin_line, 1);
	}
}