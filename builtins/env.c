/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 19:48:11 by tsierra-          #+#    #+#             */
/*   Updated: 2021/06/08 22:49:17 by tsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	builtin_env(t_list *var_lst)
{
	t_var	*var;

	while (var_lst)
	{
		var = var_lst->content;
		if (is_env(var))
		{
			ft_putstr_fd(var->name, 1);
			ft_putstr_fd("=", 1);
			ft_putstr_fd(var->value, 1);
			ft_putstr_fd("\n", 1);
		}
		var_lst = var_lst->next;
	}
	return (1);
}
