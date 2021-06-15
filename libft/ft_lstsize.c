/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:52:09 by tsierra-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/03/02 15:53:05 by tsierra-         ###   ########.fr       */
=======
/*   Updated: 2021/06/14 18:45:53 by tsierra-         ###   ########.fr       */
>>>>>>> 5f5a09d68684605e50abeacb76bd6e328a749aa3
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
<<<<<<< HEAD
	t_list	*ptr;
=======
	t_list	*current;
>>>>>>> 5f5a09d68684605e50abeacb76bd6e328a749aa3
	int		size;

	if (!lst)
		return (0);
	size = 0;
<<<<<<< HEAD
	ptr = lst;
	while (ptr)
	{
		ptr = ptr->next;
=======
	current = lst;
	while (current)
	{
		current = current->next;
>>>>>>> 5f5a09d68684605e50abeacb76bd6e328a749aa3
		size++;
	}
	return (size);
}
