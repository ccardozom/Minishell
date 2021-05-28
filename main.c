#include "minishell.h"

void	print_prompt(char *prompt)
{
	ft_putstr_fd(prompt, 1);
	ft_putstr_fd("$ ", 1);
}

void	init_environ(t_env *_env)
{
	create_empty_node(_env);
}

void	free_lista(t_env *_env)
{
	t_lista *node;

	while (_env->cli)
	{
		node = _env->cli;
		free_node(_env->cli);
		_env->cli = _env->cli->next;
		free(node);
	}
}

void	init_keyboard(t_shell *sh)
{
	sh->my_term = sh->term;
	sh->my_term.c_lflag &= ~(ECHO | ICANON);
	sh->my_term.c_cc[VMIN] = 1;
	sh->my_term.c_cc[VTIME] = 0;
	tcsetattr(1, TCSAFLUSH, &sh->my_term);
	tputs(tgetstr("ks", 0), 1, ft_putchar);
}

char	*read_command_line(t_shell *sh)
{
	char	*line;

	line = NULL;
	if (get_next_line(0, &line) < 0)
		print_error(sh, "gnl", "lecture error", 1);
	return (line);
}

void	read_eval_print_loop(t_shell *sh)
{
	char	*cmd_line;

	while (1)
	{
		cmd_line = NULL;
		print_prompt(sh->prompt);
		read_cmdline(&cmd_line, &sh->_env);
//		cmd_line = read_command_line(sh);
		sh->pipeline_lst = parser(cmd_line, sh->prompt);
		if (sh->pipeline_lst)
			executer(sh);
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

void	int_envlst(t_shell *sh, char **env)
{
	char	pwd[2048];	

	sh->env_lst = extract_env(env);
	set_var2("TERM", "xterm-256color", &sh->env_lst, NULL);
	set_var2("OLDPWD", NULL, &sh->env_lst, NULL);
	set_var2("PWD", getcwd(pwd, sizeof(char) * 2048), &sh->env_lst, modify_value2);
	set_var2("SHLVL", "1", &sh->env_lst, increase_shlvl2);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	sh;

	ft_bzero(&sh, sizeof(t_shell));
	sh.prompt = ft_strrchr(argv[0], '/') + 1;
	int_envlst(&sh, env);
	if (!sh.env_lst)
		return (1);
	init_environ(&sh._env);
	if (tgetent(0, get_env_value("TERM", sh.env_lst)) == -1)
	{
		print_error(&sh, "env", "TERM not set", 1);
		return (sh.status);
	}
	tcgetattr(1, &sh.term);
	init_keyboard(&sh);
//	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	if (argc == 1)
		read_eval_print_loop(&sh);
	tcsetattr(1, TCSANOW, &sh.term);
	return (sh.status);
}
