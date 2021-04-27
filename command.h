/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:11:29 by tsierra-          #+#    #+#             */
/*   Updated: 2021/04/27 14:26:28 by tsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <signal.h>

typedef struct s_path
{
	char	*env;
	char	*dir;
	char	*exe;
}			t_path;

int		search_directory(char *path, char *name);
char	*get_exe_path(char *name);
int		executer_command(char *path, char **argv);
void	print_command_error(char *cmd, char *prompt);

#endif