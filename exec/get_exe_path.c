/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exe_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 21:33:57 by tsierra-          #+#    #+#             */
/*   Updated: 2021/06/02 20:05:24 by tsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*is_file(char *name)
{
	struct stat	buf;

	if (stat(name, &buf) == -1)
		return (NULL);
	return (ft_strdup(name));
}

char	*get_exe_path(char *name, t_shell *sh)
{
	t_path		path;

	ft_bzero(&path, sizeof(t_path));
	if (ft_strchr(name, '/'))
		return (is_file(name));
	path.env = get_env("PATH", sh->env_lst);
	if (!path.env)
		return (NULL);
	path.env = ft_strdup(path.env);
	path.dir = ft_strtok(path.env, ":");
	while (path.dir != NULL)
	{
		if (search_directory(path.dir, name))
		{
			path.exe = ft_strjoin_btwchar(path.dir, name, '/');
			free(path.env);
			return (path.exe);
		}
		path.dir = ft_strtok(NULL, ":");
	}
	free(path.env);
	return (NULL);
}
