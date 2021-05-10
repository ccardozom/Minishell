#ifndef BUILTINS_H
# define BUILTINS_H
# include "minishell.h"

int		work_to_list(t_env *environ, char *cmd);
char	*find_node(char *str, t_lista *lst);
int		execute_command(t_env *environ, char **cmdline, char **builtins);
void	add_node_front(t_lista **lst, char *str);
void	add_node_before_last(t_lista *lst, char *str);
t_list	*modify_value(t_list *list, char *value);

#endif