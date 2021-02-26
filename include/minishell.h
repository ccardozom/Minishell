#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <sys/types.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_env
{
	char			*string;
	struct s_env	*next;
	struct s_env	*prev;
}				t_env;

typedef struct	s_all
{
	int		exit;
	int		fd;
	char	*line;
	t_env	*start;
}				t_all;

void	capture_env(t_all *mini, char **env);

#endif
