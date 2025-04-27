/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nachabi- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:13:23 by nachabi-          #+#    #+#             */
/*   Updated: 2025/01/25 13:16:46 by nachabi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_path(char **envp)
{
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
	{
		write(2, "Error: PATH not found in the environment\n", 41);
		exit(1);
	}
	return (i);
}

void	free_way_to_path(char **way_to_path)
{
	int	i;

	i = 0;
	while (way_to_path[i])
	{
		free(way_to_path[i]);
		i++;
	}
	free(way_to_path);
}

char	**split_command(char *argv)
{
	char	**cmd;
	int		i;

	i = 0;
	if (argv[0] == '\0')
	{
		write(2, "empty command!\n", 15);
		exit(1);
	}
	cmd = ft_split(argv, ' ');
	if (!cmd || !cmd[0])
	{
		while (cmd[i])
			free(cmd[i++]);
		free(cmd);
		error();
	}
	return (cmd);
}
