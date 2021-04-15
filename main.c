#include "minishell.h"

void	print_prompt(void)
{
	ft_putstr_fd("minishell$ ", 1);
}

char	*read_line(void)
{
	char	*line;

	if (get_next_line(0, &line) < 0)
	{
		ft_putstr_fd("error", 2);
	}
	return (line);
}

void	control_c(int c)
{
	c=2;
	printf("\n");
	print_prompt();
}

void	init_environ(t_env *environ)
{
	environ->lst = NULL;
	environ->cmd_line = NULL;
	environ->lst_control = NULL;
	environ->var = NULL;
	environ->cli = NULL;
	environ->cmd_buffer = NULL;
	environ->cli_len = 0;
}

int	main(int argc, char *argv[], char **env)
{
	char	*cmd;
	t_env	environ;
	int		cont;
	char	*str;

	cont = argc;
	str = *argv;
	cmd = NULL;
	init_environ(&environ);
	capture(&environ, env); //está en el archivo evn.c
	//ft_lst_iter_lst(environ.lst_control->inicio, imprimir_content);
	//signal(SIGINT, &control_c);
	while (1)
	{
		tputs(tgetstr("dl", 0), 1, ft_putchar);
		print_prompt();
		//cmd = read_line();
		read_cmdline(&cmd, &environ);
		work_to_list(&environ, cmd); //está en el archivo work_to_list.c
		if (!ft_strcmp(cmd, "exit"))
		{
			system("leaks -fullContent minishell");
			exit(0);
		}
	}
	return (0);
}
//esto es para probar pero hay que actualizarlo con la rama master