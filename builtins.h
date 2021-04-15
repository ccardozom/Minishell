#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

#define MSKEY_UP		4283163
#define MSKEY_DOWN		4348699
#define MSKEY_LEFT		4479771
#define MSKEY_RIGHT		4414235
#define MSKEY_BACKSPACE	127

int		work_to_list(t_env *environ, char *cmd);
char	*find_nodo(char *str, t_lista *lst);
int		execute_command(t_env *environ, char *built, char **builtins);

#endif