#include "minishell.h"

int	cap_key_down(t_env *environ)
{
	t_line 	*line;

	if (environ->cli->prev)
	{
		environ->cli = environ->cli->prev;
		line = environ->cli->content;
		tputs(restore_cursor, 1, ft_putchar);
		tputs(tgetstr("ed", 0), 1, ft_putchar);
		tputs(tgetstr("ce", 0), 1, ft_putchar);
		if (line->origin_line)
		{
			ft_strncpy(environ->cmd_buff, line->origin_line, ft_strlen(line->origin_line));
			environ->cli_bufflen = ft_strlen(line->origin_line);
			environ->cmd_cursor = environ->cmd_buff + environ->cli_bufflen;
		}
		ft_putstr_fd(line->origin_line, 1);
		ft_bzero(environ->ch, sizeof(environ->ch));
	}
	environ->check_esc = 0;
	return (0);
}
