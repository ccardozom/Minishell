#include "minishell.h"

void	find_history(t_env *environ)
{
	t_line	*line;

	line = environ->cli->content;
	tputs(restore_cursor, 1, ft_putchar);
	tputs(tgetstr("ed", 0), 1, ft_putchar);
	tputs(tgetstr("ce", 0), 1, ft_putchar);
	if (line->clone_line)
	{
		ft_strcpy(environ->cmd_buff, line->clone_line);
		environ->cli_bufflen = ft_strlen(line->clone_line);
		environ->cmd_cursor = environ->cmd_buff + environ->cli_bufflen;
		ft_putstr_fd(line->clone_line, 1);
	}
	else if (line->origin_line)
	{
		ft_strcpy(environ->cmd_buff, line->origin_line);
		environ->cli_bufflen = ft_strlen(line->origin_line);
		environ->cmd_cursor = environ->cmd_buff + environ->cli_bufflen;
		ft_putstr_fd(line->origin_line, 1);
	}
}
