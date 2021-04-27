#include "minishell.h"

int	cap_key_printable(t_env *environ)
{
	t_line *line;

	line = environ->cli->content;
	write(1, &environ->str, 1);
	if (environ->cli_bufflen < 2048)
	{
		*environ->cmd_cursor = *environ->ch;
		environ->cli_bufflen++;
		environ->cmd_cursor++;
	}
	if (ft_strcmp(line->origin_line, ""))
		line->clone_line = ft_strdup(environ->cmd_buff);
	ft_bzero(environ->ch, sizeof(environ->ch));
	environ->check_esc = 0;
	return (0);
}
