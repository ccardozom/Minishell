#include "minishell.h"

void	del_char_pos(t_env *environ)
{
	int	index;

	index = environ->cli_bufflen;
	while (environ->cmd_buff[index])
	{
		environ->cmd_buff[index - 1] = environ->cmd_buff[index];
		index++;
	}
	environ->cmd_buff[ft_strlen(environ->cmd_buff) - 1] = '\0';
}

void	cap_delete_char(t_env *environ)
{
	if (environ->cli_bufflen > 0)
	{
		tputs(cursor_left, 1, ft_putchar);
		tputs(tgetstr("dm", 0), 1, ft_putchar);
		tputs(tgetstr("dc", 0), 1, ft_putchar);
		tputs(tgetstr("ed", 0), 1, ft_putchar);
		environ->cmd_cursor--;
		*environ->cmd_cursor = '\0';
		del_char_pos(environ);
//		if (environ->cmd_buff[environ->cli_bufflen] == '\0')
//			environ->cmd_buff[environ->cli_bufflen - 1] = '\0';
//		else
		{
		}
		environ->cli_bufflen--;
	}
}
