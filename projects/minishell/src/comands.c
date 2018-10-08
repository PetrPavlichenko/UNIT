/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 13:47:16 by ppavlich          #+#    #+#             */
/*   Updated: 2017/11/22 13:47:18 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_fork(char **inp, char **env, char *path)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		execve(path, inp, env);
		not_found(inp[0]);
	}
	else
		wait(0);
}

int		norm_exe(char **inp, char **env, char *str)
{
	int		f;
	char	*path;

	f = 0;
	path = ft_strdup(str);
	(ft_strlen(path) > 0) ? (ft_strappend(&path, "/")) : 0;
	ft_strappend(&path, inp[0]);
	if (access(path, F_OK) == 0)
	{
		if (access(path, X_OK) == 0)
		{
			ft_fork(inp, env, path);
			f++;
		}
	}
	free(path);
	return (f);
}

void	ft_execve(char **inp, char **env)
{
	char	*t;
	char	**arr;
	int		i;

	t = 0;
	i = 0;
	arr = 0;
	if (norm_exe(inp, env, "") > 0)
		return ;
	while (env[i] && (t = ft_strnstr(env[i], "PATH", 5)) == NULL)
		i++;
	if (t)
	{
		arr = ft_strsplit(t + 5, ':');
		i = -1;
		while (arr[++i])
			if (norm_exe(inp, env, arr[i]))
				break ;
	}
	if (!arr || arr[i] == NULL)
		not_found(inp[0]);
	free_arr(arr);
}

void	home_not_set(void)
{
	g_r();
	ft_putendl_fd("minishell: $HOME not set", 2);
	r_g();
}
