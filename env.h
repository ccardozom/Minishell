#ifndef ENV_H
# define ENV_H

# include "minishell.h"

typedef struct s_variable
{
	char	*name;
	char	*value;
}			t_var;


typedef struct s_lista
{
	void			*content;
	struct s_lista	*next;
	struct s_lista	*prev;
}	t_lista;

typedef struct s_control //estructura sin uso
{
	t_lista	*inicio;
	t_lista	*fin;
	int		contador;
}	t_control;

typedef struct s_environment
{
	t_lista		*lst;
	char		*cmd_line;
	t_control	*lst_control;
	t_var		*var;
	t_lista		*cli;
	char		*cmd_buffer;
	int			cli_len;
}	t_env;

int		capture(t_env *environ, char **env);
char	**var_to_array(t_lista *lista);
t_var	*array_to_var(char *str);
int		search_var_name(void *str, void *var);
t_list	*modify_value(t_list *list, char *value);
int		*read_cmdline(char **cmd, t_env *environ);
int		ft_putchar(int c);
void	free_array(char **str);
int		ft_insert_nodo_ini(t_lista **lst, t_lista *new);
int		ft_insert_nodo_fin(t_lista **lst, t_lista *new);
void	ft_lst_iter_lst(t_lista *lst, void (*f)(void *));
int		ft_lst_size_lst(t_lista *lst);
t_lista	*ft_lst_new_lst(void *content);
void	imprimir_content(void *cabeza);	//esta definicion es para hacer pruebas de impresion de la variable content de una lista
void	imprimir_tabla(char **array);	//esta definicion es para hacer pruebas de impresion de la cadena creada
void	imprimir_lista(t_lista *cabeza); //esta definicion es para hacer pruebas de impresion de una lista

#endif
