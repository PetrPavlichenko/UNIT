/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 05:38:00 by ppavlich          #+#    #+#             */
/*   Updated: 2017/11/11 05:38:03 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char **inp, char **env)
{
	int		i;
	int		j;
	char	*t;

	i = 1;
	while (inp[i] && inp[i][0] != '\0')
	{
		i > 1 ? write(1, " ", 1) : 0;
		if (inp[i][0] == '$')
		{
			j = 0;
			while (env[j] && (t = ft_strnstr(env[j], inp[i] + 1, \
				ft_strlen(inp[i]))) == NULL)
				j++;
			if (t != NULL)
			{
				t = ft_strchr(t, '=');
				ft_putstr_echo(t + 1);
			}
		}
		else
			ft_putstr_echo(inp[i]);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_put_env(char **env)
{
	int i;

	i = -1;
	if (env)
		while (env[++i])
		{
			ft_putendl(env[i]);
		}
	else
	{
		g_r();
		ft_putendl_fd("The error occured", 2);
		r_g();
	}
}

void	ft_setenv(char **inp, char ***env)
{
	int		i;
	int		k;

	k = 1;
	while (inp[k])
	{
		i = 0;
		while (inp[k][i] != '=' && inp[k][i] != '\0')
			if (inp[k][i++] == ' ')
			{
				g_r();
				ft_putendl_fd("usage setenv: [variable]=[value]", 2);
				r_g();
				break ;
			}
		if (inp[k][i] != '=')
		{
			g_r();
			ft_putendl_fd("usage setenv: [variable]=[value]", 2);
			r_g();
			break ;
		}
		norm_setenv(inp, env, i, k);
		k++;
	}
}

void	ft_unsetenv(char **inp, char ***env)
{
	char	*str;
	int		i;
	int		k;

	k = 0;
	while (inp[++k])
	{
		str = 0;
		i = 0;
		while ((*env)[i] && (str = ft_strnstr((*env)[i], \
			inp[k], ft_strlen(inp[k]))) == NULL)
			i++;
		if (str == 0)
		{
			g_r();
			ft_putstr_fd("variable ", 2);
			ft_putstr_fd(inp[k], 2);
			write(2, ":\n", 2);
			ft_putendl_fd("does not exist", 2);
			r_g();
		}
		else
			*env = ft_unset((*env), i);
	}
}

void	check_command(char **inp, char ***env)
{
	if (!inp[0])
		return ;
	if (strcmp(inp[0], "cd") == 0)
		ft_cd(inp, env);
	else if (ft_strcmp(inp[0], "env") == 0)
		ft_put_env(*env);
	else if (ft_strcmp(inp[0], "echo") == 0)
		ft_echo(inp, *env);
	else if (ft_strcmp(inp[0], "setenv") == 0)
		ft_setenv(inp, env);
	else if (ft_strcmp(inp[0], "unsetenv") == 0)
		ft_unsetenv(inp, env);
	else if (ft_strcmp(inp[0], "exit") == 0)
		exit(1);
	else
		ft_execve(inp, *env);
}
