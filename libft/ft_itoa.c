/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:09:03 by tsierra-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/03/04 17:26:18 by tsierra-         ###   ########.fr       */
=======
/*   Updated: 2021/05/10 18:06:51 by tsierra-         ###   ########.fr       */
>>>>>>> 5f5a09d68684605e50abeacb76bd6e328a749aa3
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
<<<<<<< HEAD
=======
#include <stdio.h>
>>>>>>> 5f5a09d68684605e50abeacb76bd6e328a749aa3

static size_t	nbrlen(int nbr)
{
	size_t	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		len++;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	i;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = nbrlen(n);
<<<<<<< HEAD
	str = malloc(sizeof(char) * len + 1);
=======
	str = malloc(sizeof(char) * (len + 1));
>>>>>>> 5f5a09d68684605e50abeacb76bd6e328a749aa3
	if (!str)
		return (NULL);
	str[len] = '\0';
	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		n *= -1;
		i++;
	}
<<<<<<< HEAD
	while (i < len)
	{
		str[len--] = (n % 10) + '0';
=======
	while (len > i)
	{
		str[--len] = '0' + (n % 10);
>>>>>>> 5f5a09d68684605e50abeacb76bd6e328a749aa3
		n /= 10;
	}
	return (str);
}
