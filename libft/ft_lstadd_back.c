/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:50:17 by tsierra-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/03/01 11:50:19 by tsierra-         ###   ########.fr       */
=======
/*   Updated: 2021/06/14 18:42:00 by tsierra-         ###   ########.fr       */
>>>>>>> 5f5a09d68684605e50abeacb76bd6e328a749aa3
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
<<<<<<< HEAD
	t_list	*alst;

	alst = *lst;
	if (!alst)
		*lst = new;
	else
	{
		while (alst->next)
			alst = alst->next;
		alst->next = new;
=======
	t_list	*current;

	current = *lst;
	if (!current)
		*lst = new;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new;
>>>>>>> 5f5a09d68684605e50abeacb76bd6e328a749aa3
	}
}
