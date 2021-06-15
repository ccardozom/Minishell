/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:51:13 by tsierra-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/03/01 11:51:15 by tsierra-         ###   ########.fr       */
=======
/*   Updated: 2021/05/21 16:24:56 by tsierra-         ###   ########.fr       */
>>>>>>> 5f5a09d68684605e50abeacb76bd6e328a749aa3
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
<<<<<<< HEAD
	del(lst->content);
	free(lst);
	lst = NULL;
=======
	if (lst)
	{
		if (del)
			del(lst->content);
		free(lst);
		lst = NULL;
	}
>>>>>>> 5f5a09d68684605e50abeacb76bd6e328a749aa3
}
