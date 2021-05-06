#ifndef ENV_H
# define ENV_H
# include "minishell.h"
# define NL_KEY 10
# define DL_KEY 127
# define FALSE 0
# define TRUE 1

typedef struct s_variable
{
	char	*name;
	char	*value;
}			t_var;

typedef struct s_line
{
	char	*origin_line;
	char	*clone_line;
}			t_line;

typedef struct s_lista
{
	void			*content;
	int				index;
	struct s_lista	*next;
	struct s_lista	*prev;
}	t_lista;

typedef struct s_environment
{
	char		str;
	int			check_esc;
	char		ch[4];
	int			index_ch;
	char		*cmd_line;
	t_var		*var;
	t_lista		*lst;
	t_lista		*cli;
	t_lista		*lst_cli;
	char		cmd_buff[2048];
	char		*cmd_cursor;
	int			cli_bufflen;
}	t_env;

int		capture(t_env *environ, char **env);
int		search_var_name(void *str, void *var);
int		*read_cmdline(char **cmd, t_env *environ);
int		ft_putchar(int c);
int		ft_insert_node_ini(t_lista **lst, t_lista *new);
int		ft_insert_nodo_fin(t_lista **lst, t_lista *new);
int		ft_lst_size_lst(t_lista *lst);
int		ft_delete_node(t_lista *lst, char *str);
int		cap_key_printable(t_env *environ);
int		cap_key_left(t_env *environ);
int		cap_key_right(t_env *environ);
int		cap_key_up(t_env *environ);
int		cap_key_down(t_env *environ);
char	**var_to_array(t_lista *lista);
char	*ft_strjoin_free(char *dst, char *src);
void	find_history(t_env *environ);
int		search_env_name(char *str, t_var *var);
int		set_env(char *str, t_lista *lst);
void	cap_delete_char(t_env *environ);
void	free_array(char **str);
void	ft_lst_iter_lst(t_lista *lst, void (*f)(void *));
void	create_empty_node(t_env *environ);
void	create_node(t_env *environ);
void	create_clon_node(t_env *environ);
t_line	*next_line_key(t_env *environ);
t_var	*array_to_var(char *str);
t_lista	*ft_lst_new_lst(void *content);
void	imprimir_content(void *cabeza);
void	imprimir_tabla(char **array);
void	imprimir_lista(t_lista *cabeza);

#endif
