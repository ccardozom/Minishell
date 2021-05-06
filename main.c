#include "minishell.h"

void	print_prompt(void)
{
	ft_putstr_fd("minishell$ ", 1);
}

void	init_environ(t_env *environ)
{
	ft_bzero(environ, sizeof(t_env));
	create_empty_node(environ);
}

void	free_lista(t_env *environ)
{
	t_line	*line;

	while (environ->cli->next)
	{
		line = environ->cli->content;
		if (line->origin_line)
			free(line->origin_line);
		if (line->clone_line)
			free(line->clone_line);
		free(line);
		environ->cli = environ->cli->next;
	}
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
			free_lista(&environ);
			exit(0);
		}
	}
	return (0);
}
