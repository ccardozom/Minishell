/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:49:33 by tsierra-          #+#    #+#             */
/*   Updated: 2021/04/26 15:17:59 by tsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include "minishell.h"
# include "parser.h"
# include "fd.h"
# include "command.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>

void	executer(t_list *pipeline_lst, char *prompt);
void	executer_pipeline(t_pip *pipeline, char *prompt, t_fd *fd);
void	set_redir_fd(t_list *redir_lst, int *fd, char *prompt);
void	print_file_error(char *file, char *prompt);
void	find_command(t_cmd *cmd, char *prompt);

#endif
