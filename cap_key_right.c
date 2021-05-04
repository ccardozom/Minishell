#include "minishell.h"

int	cap_key_right(t_env *environ)
{
	t_line *line;
	int	len;

	line = environ->cli->content;
	if (line->clone_line)
		len = ft_strlen(line->clone_line);
	else
		len = ft_strlen(line->origin_line);
	if (environ->cli_bufflen < len)
	{
		tputs(tgetstr("kr", 0), 1, ft_putchar);
		environ->cli_bufflen++;
		ft_bzero(environ->ch, sizeof(environ->ch));
		environ->check_esc = 0;
	}
	return (0);
}
