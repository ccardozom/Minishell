/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:20:52 by tsierra-          #+#    #+#             */
/*   Updated: 2021/05/31 19:20:55 by tsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_env(char *name, t_list *env_lst)
{
	t_list	*lst;

	lst = ft_lstfind(env_lst, name, env_name_cmp);
	if (!lst)
		return (NULL);
	return (((t_var *)(lst->content))->value);
}
