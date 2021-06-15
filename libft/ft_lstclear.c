/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:50:46 by tsierra-          #+#    #+#             */
/*   Updated: 2021/03/15 16:54:18 by tsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*tmp;

	aux = *lst;
	tmp = NULL;
	while (aux)
	{
		tmp = aux->next;
<<<<<<< HEAD
		del(aux->content);
=======
		if (del)
			del(aux->content);
>>>>>>> 5f5a09d68684605e50abeacb76bd6e328a749aa3
		free(aux);
		aux = tmp;
	}
	*lst = NULL;
}
