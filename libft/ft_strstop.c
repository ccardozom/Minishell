/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:13:58 by ccardozo          #+#    #+#             */
/*   Updated: 2021/03/04 17:01:39 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstop(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	if (i < n && src[i] == '\0')
	{
		while (dest[i] != '\0')
		{
			dest[i] = '\0';
			++i;
		}
	}
	return (dest);
}