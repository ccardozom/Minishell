/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:15:16 by tsierra-          #+#    #+#             */
/*   Updated: 2021/03/23 18:46:58 by tsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"

int	id_token(char *str)
{
	int	id;

	id = WORD;
	if (*str == '>')
		id = GREAT;
	if (str[0] == '>' && str[1] == '>')
		id = DGREAT;
	else if (*str == '<')
		id = LESS;
	else if (*str == '|')
		id = PIPE;
	else if (*str == ';')
		id = SCOLON;
	return (id);
}

t_token	*new_token(char *str)
{
	t_token	*tkn;

	tkn = malloc(sizeof(t_token));
	if (!tkn)
		return (NULL);
	tkn->token = str;
	tkn->identifier = id_token(str);
	return (tkn);
}

void	free_token(void *tkn)
{
	t_token	*tmp;

	tmp = tkn;
	free(tmp->token);
	free(tmp);
}

void	print_token(void *tkn)
{
	t_token	*tmp;

	tmp = tkn;
	printf("token	= $%s$\n", tmp->token);
}