#include "minishell.h"
# include <termios.h>
# include <curses.h>
#include <sys/ioctl.h>

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (0);
}


void close_keyboard(struct termios ini)
{
	tcsetattr(0, TCSANOW, &ini);
}

void	delete_char(char *cmdline)
{
	int i;

	i = strlen(cmdline);
	cmdline[i] = '\0';
}

void	save_comand_line(t_env *environ)
{
	if (!environ->cli)
		environ->cli = ft_lst_new_lst(environ->cmd_buffer);
	else
		ft_insert_nodo_ini(&environ->cli, ft_lst_new_lst(environ->cmd_buffer));
}

int	*read_cmdline(char **cmd, t_env *environ)
{
	char str;
	char cmdline[2048];
	char *char_aux;
	struct termios term;
	struct termios aux;
	char ch[4];
	int i = 0;
	t_lista *lst_aux;

	tcgetattr(0, &term);
	aux = term;
	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &term);
	tgetent(0, getenv("TERM"));
	ft_bzero(cmdline, 2048);
	str = 0;
	tputs(save_cursor, 1, ft_putchar);
	environ->cmd_buffer = NULL;
	while (str != 10)
	{
		read(0, &str, 1);
		if (str != 127 && str != 10)
		{

			ch[i++] = str;
			if (!ft_strcmp(ch, "\033[A"))
			{
				tputs(restore_cursor, 1, ft_putchar);
				tputs(tgetstr("ed", 0), 1, ft_putchar);
				tputs(tgetstr("ce", 0), 1, ft_putchar);
				if (environ->cli)
				{
					lst_aux = environ->cli;
					ft_putstr_fd(lst_aux->content, 1);
					environ->cmd_buffer = (void *)lst_aux->content;
					environ->cli_len = ft_strlen(environ->cmd_buffer);
					if (environ->cli->next)
						environ->cli = environ->cli->next;
				}
				//write(1, "tecla arriba", 12);
				i = 0;
				ft_bzero(ch, 3);
			}
			else if (!ft_strcmp(ch, "\033[B"))
			{
				tputs(restore_cursor, 1, ft_putchar);
				tputs(tgetstr("ed", 0), 1, ft_putchar);
				tputs(tgetstr("ce", 0), 1, ft_putchar);
				if (environ->cli)
				{
					lst_aux = environ->cli;
					ft_putstr_fd(environ->cli->content, 1);
					environ->cmd_buffer = lst_aux->content;
					environ->cli_len = ft_strlen(environ->cmd_buffer);
					if (environ->cli->prev)
						environ->cli = environ->cli->prev;
				}
				//write(1, "tecla abajo", 11);
				i = 0;
				ft_bzero(ch, 4);
			}
			else if (!ft_strcmp(ch, "\033[D") || !ft_strcmp(ch, "\033[C"))
			{
				i = 0;
				ft_bzero(ch, 4);
			}
			else if (ft_isalpha(str) || ft_isalnum(str))
			{
				write(1, &str, 1);
				i = 0;
				if (!char_aux)
					char_aux = ft_strdup(ch);
				else
					char_aux = ft_strjoin(char_aux, ch);
				environ->cli_len = ft_strlen(char_aux);
				ft_bzero(ch, 4);
			}
		}
		else if (str == 127)
		{
			if (environ->cmd_buffer && environ->cli_len > 0)
			{
				char_aux = environ->cmd_buffer;
				tputs(cursor_left, 1, ft_putchar);
				tputs(tgetstr("dm", 0), 1, ft_putchar);
				tputs(tgetstr("dc", 0), 1, ft_putchar);
				tputs(tgetstr("ed", 0), 1, ft_putchar);
				int index_buffer = 0;
				index_buffer = ft_strlen(char_aux);
				char_aux[index_buffer - 1] = '\0';
				environ->cli_len--;
			}
		}
		else if (str == 10)
		{
			environ->cmd_buffer = char_aux;
			save_comand_line(environ);
			break;
		}
		else
		{
			printf("entra4\n");
		}
		if (environ->lst->content)
			;
		if (str != '\n')
			*cmd = &str;
	}
	tcsetattr(0, TCSANOW, &aux);
	return (0);
}