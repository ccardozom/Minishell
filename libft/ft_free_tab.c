/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:32:31 by tsierra-          #+#    #+#             */
/*   Updated: 2021/05/12 17:50:30 by ccardozo         ###   ########.fr       */
=======
/*   By: tsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:32:31 by tsierra-          #+#    #+#             */
/*   Updated: 2021/04/06 17:11:35 by tsierra-         ###   ########.fr       */
>>>>>>> 5f5a09d68684605e50abeacb76bd6e328a749aa3
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
<<<<<<< HEAD
#include <stdio.h>
=======
>>>>>>> 5f5a09d68684605e50abeacb76bd6e328a749aa3

void	ft_free_tab(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	ptr = NULL;
}
