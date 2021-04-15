#include <stdio.h>
//#include <stdlib.h>
#include <unistd.h>
//#include <curses.h>
#include <term.h>
#include <termios.h>
#include <string.h>

#define key_UP 4283163
#define key_DOWN 4348699
#define key_LEFT 4479771
#define key_RIGHT 4414235
#define key_NL 4348682
#define key_DL 4348799

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (0);
}
// 4283163 arriba
// 4348699 abajo
// 4348682 enter
// 4348799 borrar
// 4479771 izquierda
// 4414235 derecha

int main(int argc, char *argv[], char const *env[])
{
	char str[2000];
    int l;
    struct termios term;
    char *term_name;
    long ch;

    term_name = "xterm-256color";
    tcgetattr(0, &term);
    term.c_lflag &= ~ECHO;
    term.c_lflag &= ~ICANON;
    term.c_cc[VMIN] = 1;
    term.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &term);
    tgetent(0, term_name);
    while (strcmp(str, "\n"))//(ch != 10)
    {
        l = read(0, str, 100);
		write(1, &str, l);
        //l = read(0, &ch, 8);
        //printf("%ld\n",ch);
        if (!strcmp(str, "^?"))//(ch == key_UP)
        {
            tputs(tgetstr("dl",0),1,ft_putchar);
            write(1, "ARRIBA", 6);//tputs(tgetstr("sc", 0), 1, ft_putchar);
            //tputs(tgetstr("ho",0),1,ft_putchar);
        }
        /*else if (ch == key_DOWN)
        {
            tputs(tgetstr("dl",0),1,ft_putchar);
            write(1, "ABAJO", 5);
            //tputs(tgetstr("ho",0),1,ft_putchar);
        }
        else if ("kb")
        {
            printf("entra");
            tputs(delete_character,1,ft_putchar);
            tputs(tgetstr("dc",0),1,ft_putchar);
            tputs(tgetstr("ed",0),1,ft_putchar);
        }*/
        else    
            write(1, str, l);
    }
    write(1, "\n", l);
    return (0);
}
