#include "minishell.h"

// recibe un string y busca la palabra echo al principio
// si lo encuentra devuelve 0 de lo contrario devuelve 1
// --> esta función es solo para hacer pruebas

int	find_builtin(char *cmd, char *builtin)
{
	while (*builtin)
	{
		if (*cmd++ != *builtin++)
			return (1);
	}
	return (0);
}

// recibe un string y busca la palabra export al principio
// si lo encuentra devuelve 0 de lo contrario devuelve 1
// --> esta función es solo para hacer pruebas

int	find_export(char *cmd, char *builtin)
{
	while (*builtin)
		if (*cmd++ != *builtin++)
			return (1);
	return (0);
}

int	find_unset(char *cmd)
{
	char	*token;
	int		i;

	token = "unset";
	i = 0;
	while (cmd[i] != ' ')
	{
		if (cmd[i] != token[i])
			return (1);
		i++;
	}
	return (0);
}

// recibe un string y una lista
// imprime en funcion de si encuetra $ o no

void	print_echo(char **cmd)
{
	int	check;

	check = 1;
	while (*cmd && !ft_strcmp(*cmd, "-n"))
	{
		check = 0;
		cmd++;
	}
	if (*cmd)
		ft_putstr_fd(*cmd, 1);
	while (*cmd && *(++cmd))
	{
		ft_putstr_fd(" ", 1);
		ft_putstr_fd(*cmd, 1);
	}
	if (check)
		ft_putstr_fd("\n", 1);
}

//funcion para ejecutar los comandos
//esta función es solo para hacer pruebas

int	execute_builtin(int argc, char **cmdline, t_env *_env) // esto deberia recibir con argumentos, (int argc, char *argv[], char *env[])
{
	char	cwd[2048];
	int		i;
	char	**tmp;

	i = 0;
	tmp = cmdline;
	if (*cmdline)
	{
		if (!find_builtin(*cmdline, "pwd"))
		{
			getcwd(cwd, sizeof(cwd));
			printf("%s\n", cwd);
		}
		else if (!find_builtin(*cmdline, "env"))
			imprimir_tabla(var_to_array(_env->lst));
		else if (!find_builtin(*cmdline, "export"))
		{
			if (argc > 1)
				add_node_before_last(_env->lst, &*(++cmdline));
			else
				;//print_export();
		}
		else if (!find_builtin(*cmdline, "unset"))
			ft_delete_node(_env->lst, &*(++cmdline));
		else if (!find_builtin(*cmdline, "echo"))
		{
			cmdline++;
			print_echo(cmdline);
		}
	}
	return (0);
}

//funcion para encontrar los comandos
//esta función es solo para hacer pruebas

int	work_to_list(t_env *_env, char *cmd)
{
	char	**cmdline;
	int		len;
	//builtins[5] = "cd";
	//builtins[6] = "exit";
	if (cmd)
	{
		len = 0;
		cmdline = ft_split(cmd, ' ');
		while (cmdline[len])
			len++;
		printf("len: %d\n", len);
		execute_builtin(len, cmdline, _env);
		while (_env->lst && _env->lst->prev != NULL)
			_env->lst = _env->lst->prev;
		ft_free_tab(cmdline);
	}
	return (0);
}
