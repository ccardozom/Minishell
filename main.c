#include "minishell.h"

void	print_prompt(void)
{
	ft_putstr_fd("minishell$ ", 1);
}

void	init_environ(t_env *environ)
{
	ft_bzero(environ, sizeof(t_env));
	environ->cmd_cursor = environ->cmd_buff;
	create_empty_node(environ);
}

int	main(int argc, char *argv[], char **env)
{
	char	*cmd;
	t_env	environ;

	init_environ(&environ);
	capture(&environ, env);
	while (TRUE)
	{
		tputs(tgetstr("dl", 0), 1, ft_putchar);
		print_prompt();
		cmd = NULL;
		read_cmdline(&cmd, &environ);
		work_to_list(&environ, cmd);
		if (!ft_strcmp(cmd, "exit"))
		{
			system("leaks -fullContent minishell");
			exit(0);
		}
	}
	return (0);
}
