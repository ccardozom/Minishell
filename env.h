#ifndef ENV_H
# define ENV_H
<<<<<<< HEAD
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

=======
//# include "minishell.h"
# define NL_KEY 10
# define DL_KEY 127
# define CTRL_D 4
# define CTRL_C 3
# define TAB 9
# define ESC 27
# define FALSE 0
# define TRUE 1

>>>>>>> 5f5a09d68684605e50abeacb76bd6e328a749aa3
typedef struct s_line
{
	char	*origin_line;
	char	*clone_line;
}			t_line;

typedef struct s_lista
{
	void			*content;
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
<<<<<<< HEAD
	t_var		*var;
	t_lista		*lst;
	t_lista		*cli;
	t_lista		*lst_cli;
=======
	t_lista		*cli;
>>>>>>> 5f5a09d68684605e50abeacb76bd6e328a749aa3
	char		cmd_buff[2048];
	char		*cmd_cursor;
	int			cli_bufflen;
	int			len_cursor;
<<<<<<< HEAD
}	t_env;

int		capture(t_env *_env, char **env);
int		search_var_name(void *str, void *var);
int		*read_cmdline(char **cmd, t_env *_env);
int		ft_putchar(int c);
int		ft_insert_node_ini(t_lista **lst, t_lista *new);
int		ft_insert_nodo_fin(t_lista **lst, t_lista *new);
int		ft_lst_size_lst(t_lista *lst);
int		cap_key_printable(t_env *_env);
int		cap_key_left(t_env *_env);
int		cap_key_right(t_env *_env);
int		cap_key_up(t_env *_env);
int		cap_key_down(t_env *_env);
char	**var_to_array(t_lista *lista);
char	*ft_strjoin_free(char *dst, char *src);
void	find_history(t_env *_env);
int		search_env_name(char *str, t_var *var);
int		set_env(char *str, t_lista *lst);
void	cap_delete_char(t_env *_env);
void	free_array(char **str);
void	free_node(t_lista *node);
void	ft_lst_iter_lst(t_lista *lst, void (*f)(void *));
void	create_empty_node(t_env *_env);
void	create_node(t_env *_env);
void	create_clon_node(t_env *_env);
char	*next_line_key(t_env *_env);
t_var	*array_to_var(char *str);
t_lista	*ft_lst_new_lst(void *content);
void	imprimir_content(void *cabeza);
void	imprimir_tabla(char **array);
=======
}	t_cap;

void	error_malloc(void);
int		capture(t_cap *cap, char **env);
int		search_var_name(void *str, void *var);
int		*read_cmdline(char **cmd, t_cap *cap);
int		ft_putchar(int c);
int		ft_insert_node_ini(t_lista **lst, t_lista *new);
int		ft_insert_nodo_fin(t_lista **lst, t_lista *new);
int		cap_key_printable(t_cap *cap);
int		cap_key_left(t_cap *cap);
int		cap_key_right(t_cap *cap);
int		cap_key_up(t_cap *cap);
int		cap_key_down(t_cap *cap);
int		cap_control(t_cap *cap, char **cmd);
char	**var_to_array(t_lista *lista);
void	find_history(t_cap *cap);
int		set_env(t_lista *lst, char *name, char *new_value);
void	cap_delete_char(t_cap *cap);
void	free_array(char **str);
void	free_node(t_lista *node);
void	create_empty_node(t_cap *cap);
void	create_node(t_cap *cap);
void	create_clon_node(t_cap *cap);
char	*next_line_key(t_cap *cap);
t_lista	*ft_dlstnew(void *content);
void	imprimir_content(void *cabeza);
int		imprimir_tabla(char **array);
>>>>>>> 5f5a09d68684605e50abeacb76bd6e328a749aa3
void	imprimir_lista(t_lista *cabeza);

#endif
