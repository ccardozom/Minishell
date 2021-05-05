#include "minishell.h"

int	cap_key_right(t_env *lst_env)
{
	// t_line *line;
	// int	len;

	// line = lst_env->cli->content;
	// if (line->clone_line)
	// 	len = ft_strlen(line->clone_line);
	// else
	// 	len = ft_strlen(line->origin_line);
	// if (lst_env->cli_bufflen < len)
	// {
	// 	tputs(tgetstr("kr", 0), 1, ft_putchar);
	// 	lst_env->cli_bufflen++;
	 	ft_bzero(lst_env->ch, sizeof(lst_env->ch));
	 	lst_env->check_esc = 0;
	// }
	return (0);
}
