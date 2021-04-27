/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 08:51:32 by ccardozo          #+#    #+#             */
/*   Updated: 2021/03/04 14:39:22 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content)
{
	t_list		*list;

	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
		list->content = NULL;
	else
		list->content = (void*)content;
	list->next = NULL;
	return (list);
}
