/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:24:00 by mreis-me          #+#    #+#             */
/*   Updated: 2022/07/17 22:31:06 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	send_cmd(char *args, char *envp[])
{
	char	**paths;
	char	**cmd;
	int		i;

	i = 0;
	cmd = get_cmd(args);
	if (cmd == NULL)
		msg_error("Error: Command", 2); // Ver a necessidade desse teste
	paths = get_path(envp);
	if (paths == NULL)
		msg_error("Error: no PATH", 2);
	while (paths[i++])
		exec_cmd(paths, cmd, i);
	ft_free(cmd);
	ft_free(paths);
	msg_perror("Error", EXIT_FAILURE);
}
