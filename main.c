<<<<<<< HEAD
#include "minishell.h"

void	print_prompt(void)
{
	ft_putstr_fd("minishell$ ", 1);
}

void	init_environ(t_env *_env)
{
	ft_bzero(_env, sizeof(t_env));
	create_empty_node(_env);
}

void	free_lista(t_env *_env)
{
	t_line	*line;

	while (_env->cli->next)
	{
		line = _env->cli->content;
		if (line->origin_line)
			free(line->origin_line);
		if (line->clone_line)
			free(line->clone_line);
		free(line);
		_env->cli = _env->cli->next;
	}
}

void	init_keyboard(struct termios term)
{
	struct termios	aux;

	aux = term;
	aux.c_lflag &= ~(ECHO | ICANON);
	aux.c_cc[VMIN] = 1;
	aux.c_cc[VTIME] = 0;
	tcsetattr(1, TCSAFLUSH, &aux);
	tputs(tgetstr("ks", 0), 1, ft_putchar);
}

int	main(int argc, char *argv[], char **env)
{
	struct termios	term;
	char			*cmd;
	t_env			_env;

	ft_bzero(&term, sizeof(struct termios));
	init_environ(&_env);
	tgetent(0, getenv("TERM"));
	tcgetattr(1, &term);
	init_keyboard(term);
	capture(&_env, env);
	while (TRUE)
	{
		print_prompt();
		cmd = NULL;
		read_cmdline(&cmd, &_env);
		work_to_list(&_env, cmd);
		if (!ft_strcmp(cmd, "exit"))
		{
			free_lista(&_env);
			system("leaks minishell");
			exit(0);
		}
	}
	tcsetattr(1, TCSANOW, &term);
	return (0);
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:51:54 by tsierra-          #+#    #+#             */
/*   Updated: 2021/06/14 18:42:39 by tsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_prompt(char *prompt)
{
	ft_putstr_fd(prompt, 1);
	ft_putstr_fd("$ ", 1);
}

char	*get_prompt(char *arg1)
{
	char	*pos;

	pos = ft_strrchr(arg1, '/');
	if (!pos)
		return (arg1);
	return (pos + 1);
}

void	read_eval_print_loop(t_shell *sh)
{
	char	*cmd_line;

	while (1)
	{
		cmd_line = NULL;
		print_prompt(sh->prompt);
		tcsetattr(1, TCSAFLUSH, &sh->my_term);
		tputs(tgetstr("ks", 0), 1, ft_putchar);
		read_cmdline(&cmd_line, &sh->cap);
		tcsetattr(1, TCSANOW, &sh->term);
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

int	main(int argc, char **argv, char **env)
{
	t_shell	sh;

	ft_bzero(&sh, sizeof(t_shell));
	sh.prompt = get_prompt(argv[0]);
	init_envlst(&sh, env);
	if (!sh.env_lst)
		return (1);
	init_environ(&sh.cap);
	if (tgetent(0, get_env("TERM", sh.env_lst)) == -1)
	{
		print_error(&sh, "env", "TERM not set", 1);
		return (sh.status);
	}
	tcgetattr(1, &sh.term);
	init_keyboard(&sh);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	if (argc == 1)
		read_eval_print_loop(&sh);
	tcsetattr(1, TCSANOW, &sh.term);
	return (sh.status);
>>>>>>> 5f5a09d68684605e50abeacb76bd6e328a749aa3
}
