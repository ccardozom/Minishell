#include "minishell.h"

// recibe un string y busca la palabra echo al principio
// si lo encuentra devuelve 0 de lo contrario devuelve 1
// --> esta función es solo para hacer pruebas

int	encuentra_echo(char *cmd)
{
	char	*token;
	int		i;

	token = "echo";
	i = 0;
	while (cmd[i] != ' ')
	{
		if (cmd[i] != token[i])
			return (1);
		i++;
	}
	return (0);
}

// recibe un string y busca la palabra export al principio
// si lo encuentra devuelve 0 de lo contrario devuelve 1
// --> esta función es solo para hacer pruebas

int	encuentra_export(char *cmd)
{
	char	*token;
	int		i;

	token = "export";
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

void	print_echo(char *cmd, t_lista *lst)
{
	char	*var;

	while (*cmd != ' ')
		cmd++;
	cmd++;
	if (*cmd == '$')
	{
		cmd++;
		var = find_node(cmd, lst);
		if (var)
			printf("%s\n", var);
		else if (!var)
			printf("\n");
		else
			printf("$\n");
	}
	else
		printf("%s\n", cmd);
}

//funcion para ejecutar los comandos
//esta función es solo para hacer pruebas

int	execute_command(t_env *environ, char *cmd, char **builtins)
{
	char	cwd[2048];

	if (!ft_strcmp(builtins[2], cmd))
	{
		getcwd(cwd, sizeof(cwd));
		printf("%s\n", cwd);
	}
	else if (!ft_strcmp(builtins[5], cmd))
	{
		imprimir_tabla(var_to_array(environ->lst));
	}
	else if (encuentra_export(cmd) == 0)
	{
		add_node_before_last(environ->lst, cmd);
	}
	else if (encuentra_echo(cmd) == 0)
	{
		print_echo(cmd, environ->lst);
	}
	return (0);
}

//funcion para encontrar los comandos
//esta función es solo para hacer pruebas

int	work_to_list(t_env *environ, char *cmd)
{
	char	**builtins;

	builtins = (char **)malloc(sizeof(char *) * 7);
	builtins[0] = "echo";
	builtins[1] = "cd";
	builtins[2] = "pwd";
	builtins[3] = "export";
	builtins[4] = "unset";
	builtins[5] = "env";
	builtins[6] = "exit";
	execute_command(environ, cmd, builtins);
	while (environ->lst && environ->lst->prev != NULL)
		environ->lst = environ->lst->prev;
	free(builtins);
	return (0);
}
