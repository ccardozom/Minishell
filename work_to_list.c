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

void	print_echo(char **cmd, t_lista *lst)
{
	char	*value;
	char	*str_aux;
	int		check;

	check = 0;
	if (!ft_strcmp(*cmd, "-n"))
	{
		check = 1;
		cmd++;
	}
	if (**cmd == '$')
	{
		str_aux = *cmd;
		str_aux++;
		if (*str_aux != '\0')
		{
			value = find_node(str_aux, lst);
			if (value && check)
				ft_putstr_fd(value, 1);
			else if (value)
				printf("%s\n", value);
			else if (!value)
				printf("\n");
		}
		else
			printf("$\n");
	}
	else if (!check)
		printf("%s\n", *cmd);
	else
		ft_putstr_fd(*cmd, 1);
}

//funcion para ejecutar los comandos
//esta función es solo para hacer pruebas

int	execute_builtin(t_env *environ, char **cmdline, char **builtins)
{
	char	cwd[2048];
	int		i;

	i = 0;
	if (*cmdline)
	{
		if (!find_builtin(*cmdline, builtins[i]))
		{
			getcwd(cwd, sizeof(cwd));
			printf("%s\n", cwd);
		}
		else if (!find_builtin(*cmdline,  builtins[++i]))
		{
			imprimir_tabla(var_to_array(environ->lst));
		}
		else if (!find_builtin(*cmdline,  builtins[++i]))
		{
			add_node_before_last(environ->lst,  cmdline[1]);
		}
		else if (!find_builtin(*cmdline,  builtins[++i]))
		{
			ft_delete_node(environ->lst, cmdline[1]);
		}
		else if (!find_builtin(*cmdline,  builtins[++i]))
		{
			while (cmdline[i])
				i++;
			if (i > 0)
				cmdline++;
			print_echo(cmdline, environ->lst);
		}
	}
	return (0);
}

//funcion para encontrar los comandos
//esta función es solo para hacer pruebas

int	work_to_list(t_env *environ, char *cmd)
{
	char	**builtins;
	char	**cmdline;

	builtins = (char **)malloc(sizeof(char *) * 7);
	builtins[0] = "pwd";
	builtins[1] = "env";
	builtins[2] = "export";
	builtins[3] = "unset";
	builtins[4] = "echo";
	builtins[5] = "cd";
	builtins[6] = "exit";
	cmdline = ft_split(cmd, ' ');
	execute_builtin(environ, cmdline, builtins);
	while (environ->lst && environ->lst->prev != NULL)
		environ->lst = environ->lst->prev;
	free(builtins);
	return (0);
}
