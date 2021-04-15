/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:50:46 by tsierra-          #+#    #+#             */
/*   Updated: 2021/03/15 16:31:04 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include "../builtins.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*tmp;

	aux = *lst;
	tmp = NULL;
	while (aux)
	{
		tmp = aux->next;
		del(aux->content);
		free(aux);
		aux = tmp;
	}
	
	*lst = NULL;
}
