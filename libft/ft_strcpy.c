/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 17:43:25 by ccardozo          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/05/05 11:23:02 by ccardozo         ###   ########.fr       */
=======
/*   Updated: 2021/06/02 20:16:38 by tsierra-         ###   ########.fr       */
>>>>>>> 5f5a09d68684605e50abeacb76bd6e328a749aa3
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
char *ft_strcpy(char *dest, char *src)
{
	int i;
=======
char	*ft_strcpy(char *dest, char *src)
{
	int	i;
>>>>>>> 5f5a09d68684605e50abeacb76bd6e328a749aa3

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
<<<<<<< HEAD
}
=======
}
>>>>>>> 5f5a09d68684605e50abeacb76bd6e328a749aa3
