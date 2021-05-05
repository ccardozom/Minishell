#include "minishell.h"

void	cap_delete_char(t_env *lst_env)
{
	if (lst_env->cli_bufflen > 0)
	{
		tputs(cursor_left, 1, ft_putchar);
		tputs(tgetstr("dm", 0), 1, ft_putchar);
		tputs(tgetstr("dc", 0), 1, ft_putchar);
		tputs(tgetstr("ed", 0), 1, ft_putchar);
		lst_env->cmd_cursor--;
		lst_env->cli_bufflen--;
		*lst_env->cmd_cursor = '\0';
	}
	else
		tputs(tgetstr("te", 0), 1, ft_putchar);
}
