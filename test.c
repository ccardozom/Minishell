#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <term.h>
#include <curses.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

static struct termios ini, new;

#define MSKEY_UP		4283163
#define MSKEY_DOWN		4348699
#define MSKEY_LEFT		4479771
#define MSKEY_RIGHT		4414235
#define MSKEY_BACKSPACE	127


int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (0);
}

void init_keyboard()
{
	tcgetattr(0, &ini);
	new = ini;
	new.c_lflag &= ~ECHO;
	new.c_lflag &= ~ICANON;
	new.c_cc[VMIN] = 1;
	new.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &new);
}

void close_keyboard()
{
	tcsetattr(0, TCSANOW, &ini);
}

int main(int argc, char *argv[], char const *envp[])
{
	long str;
	int l;
	struct termios term;
	char *buffer;
	size_t pos;

	init_keyboard();
	tgetent(0, getenv("TERM"));
	buffer = malloc(1025);
	str = 0;
	while (str != 4)
	{
		pos = 0;
		buffer[pos] = '\0';
		write(1, "prompt> ", 8);
		tputs(save_cursor, 0, ft_putchar);
		do
		{
			str = 0;
			l = read(STDIN_FILENO, &str, 8);
			if (str == 10)
				break ;
			else if (isupper(str) || islower(str) || isdigit(str) || isspace(str))
			{
				write(1, &str, 1);
				buffer[pos] = str;
				pos++;
				buffer[pos] = '\0';
			}
			else if (str == MSKEY_UP)
			{
				tputs(restore_cursor, 1, ft_putchar);
				tgetstr("do", 0);
				tputs(tgetstr("ed", &buffer), 1, ft_putchar);
			}
			else if (str == MSKEY_LEFT)
			{
				tputs(cursor_left, 1, ft_putchar);
				pos--;
			}
			else if (str == MSKEY_BACKSPACE)
			{	
				tputs(tgetstr("dc", 0), 1, ft_putchar);
				tputs(cursor_left, 1, ft_putchar);
				buffer[pos] = '\0';
				pos--;
			}
			else if (str == 4 && pos == 0)
			{
				printf("\nexit\n");
				break ;
			}
			else
				printf("code = %li\n", str);
		} while (1);
		if (buffer[0])
			printf("Valor = '%s'", buffer);
		write(1, "\n", 1);
	}
	close_keyboard();
	return 0;
}