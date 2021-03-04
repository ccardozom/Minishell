#include "../include/minishell.h"

int	main(int argc, char *argv[], char **env)
{
	t_all	mini;
	int		pid;

	mini.exit = 0;
	capture_env(&mini, env);
	mini.line = strdup("");
	while (mini.exit == 0)
	{
		write(1, "minishell: ", 12);
		mini.fd = read(0, mini.line, 1024);
		if (!mini.line)
			mini.line = "\n";
		else
		{
			break ;
		}
		printf("%s", mini.line);
		ft_memset(mini.line, 0, ft_strlen(mini.line));
	}
	return (0);
}
