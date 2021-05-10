#include "minishell.h"
#include <termios.h>
#include <curses.h>
#include <sys/ioctl.h>

void	init_keyboard(struct termios term)
{
	struct termios	aux;

	aux = term;
	aux.c_lflag &= ~(ECHO);
	aux.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &aux);
	tgetent(0, getenv("TERM"));
	tputs(tgetstr("ks", 0), 1, ft_putchar);
}

void	init_aux(t_env *lst_env, struct termios term)
{
	init_keyboard(term);
	lst_env->str = '\0';
	lst_env->index_ch = 0;
	lst_env->check_esc = 0;
	lst_env->cmd_cursor = lst_env->cmd_buff;
}

void	control_key(t_env *lst_env)
{
	if (lst_env->str == '\e')
		lst_env->check_esc = TRUE;
	if (!ft_strcmp(lst_env->ch, tgetstr("ku", 0)))
		lst_env->index_ch = cap_key_up(lst_env);
	else if (!ft_strcmp(lst_env->ch, tgetstr("kd", 0)))
		lst_env->index_ch = cap_key_down(lst_env);
	else if (!ft_strcmp(lst_env->ch, tgetstr("kr", 0)))
		;
	else if (!ft_strcmp(lst_env->ch, tgetstr("kl", 0)))
		;
	else if (ft_isprint(lst_env->str) && lst_env->check_esc == FALSE)
		lst_env->index_ch = cap_key_printable(lst_env);
}

int	*read_cmdline(char **cmd, t_env *lst_env)
{
	struct termios	term;
	t_line			*line;

	tcgetattr(0, &term);
	init_aux(lst_env, term);
	tputs(save_cursor, 1, ft_putchar);
	while (lst_env->str != NL_KEY)
	{
		read(0, &lst_env->str, 1);
		if (lst_env->str != DL_KEY && lst_env->str != NL_KEY)
		{
			lst_env->ch[lst_env->index_ch++] = lst_env->str;
			control_key(lst_env);
		}
		else if (lst_env->str == DL_KEY)
			cap_delete_char(lst_env);
		else if (lst_env->str == NL_KEY)
		{
			line = next_line_key(lst_env);
			*cmd = line->origin_line;
			break ;
		}
	}
	tcsetattr(0, TCSANOW, &term);
	return (0);
}
