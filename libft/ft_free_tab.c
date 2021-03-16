/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:32:31 by tsierra-          #+#    #+#             */
/*   Updated: 2021/03/08 16:21:10 by tsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(char **ptr)
{
	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(*ptr);
	ptr = NULL;
}