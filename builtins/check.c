/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:58:28 by tsierra-          #+#    #+#             */
/*   Updated: 2021/05/14 15:19:15 by tsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	builtin_pwd(t_shell *sh)
{
	char	pwd[2048];

	if (getcwd(pwd, sizeof(char) * 2048))
	{
		ft_putstr_fd(pwd, 1);
		ft_putstr_fd("\n", 1);
		sh->status = 0;
	}
	return (1);
}

int	builtin_env(t_shell *sh)
{
	char	**envp;
	int		i;
	
	i = 0;
	envp = var_to_array(sh->_env.env_lst);
	if (!envp)
		return (1);
	while (envp && envp[i])
	{
		ft_putstr_fd(envp[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	ft_free_tab(envp);
	return (0);
}

int	builtin_echo(t_shell *sh, char **argv)
{
	int	newline_char;

	newline_char = 1;
	while (*argv && !ft_strcmp(*argv, "-n"))
	{
		newline_char = 0;
		argv++;
	}
	if (*argv)
		ft_putstr_fd(*argv, 1);
	while (*argv && *(++argv))
	{
		ft_putstr_fd(" ", 1);
		ft_putstr_fd(*argv, 1);
	}
	if (newline_char)
		ft_putstr_fd("\n", 1);
	sh->status = 0;
	return (1);
}

void	export_env(t_shell *sh)
{
	sh->status = 0;
}

void	ft_sort_tab(char **tab_ptr)
{
	char	*aux;
	char	**ptr;

	while (*tab_ptr)
	{
		ptr = tab_ptr;
		ptr++;
		while (*ptr)
		{
			if (**tab_ptr > **ptr)
			{
				aux = *tab_ptr;
				*tab_ptr = *ptr;
				*ptr = aux;
			}
			else
				ptr++;
		}
		tab_ptr++;
	}
}

int	print_declare_env(t_shell *sh)
{
	char	**envp;
	char	*ptr;
	int		i;

	envp = var_to_array(sh->_env.env_lst);
	if (!envp)
		return (1);
	ft_sort_tab(envp);
	i = 0;
	while (envp[i])
	{
		ft_putstr_fd("declare -x ", 1);
		ptr = envp[i];
		while (*ptr != '=')
			ft_putchar_fd(*(ptr++), 1);
		ft_putchar_fd(*(ptr++), 1);
		ft_putchar_fd('\"', 1);
		while (*ptr != '\0')
			ft_putchar_fd(*(ptr++), 1);
		ft_putchar_fd('\"', 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_free_tab(envp);
	return (0);
}

int	builtin_export(t_shell *sh, int argc, char **argv)
{
	if (argc < 1)
	{
		(void)argv;
//		export_env(sh, argv++);
	}
	else
		sh->status = print_declare_env(sh);
	return (1);
}

int	check_builtin(t_shell *sh, int argc, char **argv)
{
	int ret;

	ret = 0;
	if (argc > 0)
	{
		if (!ft_strcmp(argv[0], "cd"))
			ret = builtin_cd(sh, argc, argv);
		else if (!ft_strcmp(argv[0], "exit"))
			ret = builtin_exit(sh, argc, argv);
		else if (!ft_strcmp(argv[0], "pwd"))
			ret = builtin_pwd(sh);
		else if (!ft_strcmp(argv[0], "env"))
			ret = builtin_env(sh);
		else if (!ft_strcmp(argv[0], "export"))
			ret = builtin_export(sh, argc, argv);
		else if (!ft_strcmp(argv[0], "unset"))
			ret = ft_delete_node(sh->_env.env_lst, &*(++argv));
		else if (!ft_strcmp(argv[0], "echo"))
			ret = builtin_echo(sh, &argv[1]);
	}
	return (ret);
}

void	print_builtin_error(t_shell *sh, char **argv, char *str, int status)
{
	ft_putstr_fd(sh->prompt, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(argv[0], 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(argv[1], 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	sh->status = status;
}
