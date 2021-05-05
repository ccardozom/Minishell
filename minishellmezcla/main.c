#include "minishell.h"
# include "parser.h"
# include "executer.h"

void	print_prompt(char *prompt)
{
	ft_putstr_fd(prompt, 1);
	ft_putstr_fd("$ ", 1);
}

void	init_environ(t_env *lst_env)
{
	ft_bzero(lst_env, sizeof(t_env));
	create_empty_node(lst_env);
}

char	*read_command_line(char **cmd, t_env *lst_env)
{
	read_cmdline(&(*cmd), lst_env);
	return (*cmd);
}

void	read_eval_print_loop(t_shell *sh, char **env)
{
	char	*cmd_line;
	t_env	lst_env;

	init_environ(&lst_env);
	capture(&lst_env, env);
	while (1)
	{
		tputs(tgetstr("dl", 0), 1, ft_putchar);
		print_prompt(sh->prompt);
		cmd_line = NULL;
		read_command_line(&cmd_line, &lst_env);
		sh->tree_lst = parser(cmd_line, sh->prompt);
		if (sh->tree_lst)
			executer(sh->tree_lst, sh->prompt);
		if (!ft_strcmp(cmd_line, "exit"))
		{
			free(cmd_line);
			system("leaks minishell");
			exit(EXIT_SUCCESS);
		}
	}
}

void	sig_handler(int sig)
{
	if (sig == SIGQUIT)
	{
		ft_putstr_fd("Quit: ", 1);
		ft_putnbr_fd(sig, 1);
	}
	ft_putchar_fd('\n', 1);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	sh;

//	signal(SIGINT, sig_handler);
//	signal(SIGQUIT, sig_handler);
	ft_bzero(&sh, sizeof(sh));
	sh.prompt = ft_strrchr(argv[0], '/') + 1;
	if (argc == 1)
		read_eval_print_loop(&sh, env);
	return (0);
}
