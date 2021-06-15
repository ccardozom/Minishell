/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:02:41 by tsierra-          #+#    #+#             */
/*   Updated: 2021/05/11 16:58:45 by ccardozo         ###   ########.fr       */
=======
/*   By: tsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:02:41 by tsierra-          #+#    #+#             */
/*   Updated: 2021/03/04 15:27:01 by tsierra-         ###   ########.fr       */
>>>>>>> 5f5a09d68684605e50abeacb76bd6e328a749aa3
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
<<<<<<< HEAD

static int	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
=======
#include <stdio.h>

static int	ft_word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
>>>>>>> 5f5a09d68684605e50abeacb76bd6e328a749aa3
	}
	return (count);
}

<<<<<<< HEAD
static char	*ft_word(char const *s, char c, int i)
{
	char	*word;
	int		o;
	int		p;

	p = i;
	while (p >= 0 && s[p] != c)
		p--;
	o = i - p;
	word = (char *)malloc(sizeof(char) * (o + 1));
	p = i;
	while (p > 0 && s[p - 1] != c)
		p--;
	o = 0;
	while (p <= i)
	{
		word[o] = s[p];
		o++;
		p++;
	}
	word[o] = '\0';
	return (word);
}

static void	ft_clean(char **str, int a)
{
	int		i;

	i = 0;
	while (i < a)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char		**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;

	if (!s ||
			!(result = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1))))
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			result[j] = ft_word(s, c, i);
			if (result[j] == NULL)
			{
				ft_clean(result, j);
				return (0);
			}
			j++;
		}
		i++;
	}
	result[j] = NULL;
	return (result);
=======
static int	ft_strnlen(char const *s, char c)
{
	int	count;

	count = 0;
	while (s[count] != c && s[count] != '\0')
		count++;
	return (count);
}

static int	ft_tablecpy(char const *s, char **table, char c)
{
	int		word;
	int		i;
	int		j;

	word = 0;
	i = 0;
	j = 0;
	while (word < ft_word_count(s, c))
	{
		table[word] = malloc(sizeof(char) * ft_strnlen(&s[i], c) + 1);
		if (!table[word])
			return (0);
		j = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			table[word][j++] = s[i++];
		table[word++][j] = '\0';
	}
	table[word] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**table;

	if (!s)
		return (NULL);
	table = malloc(sizeof(char *) * ft_word_count(s, c) + 1);
	if (!table)
		return (NULL);
	if (!ft_tablecpy(s, table, c))
		return (NULL);
	return (table);
>>>>>>> 5f5a09d68684605e50abeacb76bd6e328a749aa3
}
