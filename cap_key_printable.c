#include "minishell.h"

int	cap_key_printable(t_env *environ, t_lista *lst_aux)
{
	lst_aux++;
	write(1, &environ->str, 1);
	if (environ->cli_bufflen < 2048)
	{
		*environ->cmd_cursor = *environ->ch;
		environ->cli_bufflen++;
		environ->cmd_cursor++;
	}

/*
	if (!*environ->cmd_buff)
	{
		*environ->cmd_buff = *environ->ch;
		environ->cli_bufflen++;
		environ->cmd_buff[environ->cli_bufflen] = '\0';
	}
	else if (lst_aux)
	{
		environ->cmd_buff = ft_strjoin_free(environ->cmd_buff, environ->ch);
		environ->cli_bufflen++;
		lst_aux->content = environ->cmd_buff;
	}
	else if (environ->cmd_buff)
	{
		environ->cmd_buff = ft_strjoin_free(environ->cmd_buff, environ->ch);
		environ->cli_bufflen++;
	}
	*/
	ft_bzero(environ->ch, sizeof(environ->ch));
	environ->check_esc = 0;
	return (0);
}
