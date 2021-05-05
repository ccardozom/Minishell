/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:00:45 by tsierra-          #+#    #+#             */
/*   Updated: 2021/05/05 13:58:15 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include "env.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <limits.h>
# include <termios.h>
# include <curses.h>
#include <ctype.h>
#include <term.h>

typedef struct s_shell
{
	char	*prompt;
	t_list	*tree_lst;
}			t_shell;

void	print_prompt(char *prompt);
char	*read_command_line(char **cmd, t_env *lst_env);
void	read_eval_print_loop(t_shell *sh, char **env);

#endif
