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

void	ini_aux(t_env *environ)
{
	environ->str = 0;
	environ->str_aux = NULL;
	environ->lst_aux = NULL;
	environ->index_ch = 0;
	environ->check_esc = 0;
}

void	control_key(t_env *environ)
{
	if (environ->str == '\e')
		environ->check_esc = TRUE;
	if (!ft_strcmp(environ->ch, tgetstr("ku", 0)))
		environ->index_ch = cap_key_up(environ);
	else if (!ft_strcmp(environ->ch, tgetstr("kd", 0)))
		environ->index_ch = cap_key_down(environ);
	else if (!ft_strcmp(environ->ch, tgetstr("kl", 0)))
		environ->index_ch = cap_key_left(environ);
	else if (!ft_strcmp(environ->ch, tgetstr("kr", 0)))
		environ->index_ch = cap_key_right(environ);
	else if (ft_isprint(environ->str) && environ->check_esc == FALSE)
		environ->index_ch = cap_key_printable(environ);
}

int	*read_cmdline(char **cmd, t_env *environ)
{
	struct termios	term;
	t_line *line;

	tcgetattr(0, &term);
	init_keyboard(term);
	ini_aux(environ);
	tputs(save_cursor, 1, ft_putchar);
	while (environ->str != NL_key)
	{
		read(0, &environ->str, 1);
		if (environ->str != DL_key && environ->str != NL_key)
		{
			environ->ch[environ->index_ch++] = environ->str;
			control_key(environ);
		}
		else if (environ->str == DL_key)
			cap_delete_char(environ);
		else if (environ->str == NL_key)
		{
			line = next_line_key(environ);
			*cmd = line->origin_line;
			break ;
		}
	}
	printf("cmd: %s\n", *cmd);
	tcsetattr(0, TCSANOW, &term);
	return (0);
}
