#include "minishell.h"

void	cap_delete_char(t_env *environ)
{
	if (environ->cli_bufflen > 0)
	{
		tputs(cursor_left, 1, ft_putchar);
		tputs(tgetstr("dm", 0), 1, ft_putchar);
		tputs(tgetstr("dc", 0), 1, ft_putchar);
		tputs(tgetstr("ed", 0), 1, ft_putchar);
		environ->cmd_cursor--;
		environ->cli_bufflen--;
		*environ->cmd_cursor = '\0';
	}
	else
		tputs(tgetstr("te", 0), 1, ft_putchar);
}
