/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 08:21:35 by ppavlich          #+#    #+#             */
/*   Updated: 2017/11/13 08:21:37 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getpwd(void)
{
	char	*buff;
	int		i;

	i = 100;
	buff = (char *)malloc(i);
	while (getcwd(buff, i) == NULL)
	{
		buff ? free(buff) : 0;
		i += 100;
		buff = (char *)malloc(i);
	}
	ft_strappend(&buff, "/");
	return (buff);
}

void	free_arr(char **arr)
{
	int		i;

	if (arr != 0)
	{
		i = -1;
		while (arr[++i] != 0)
			free(arr[i]);
		free(arr);
	}
}

char	**alloc_env(char **env)
{
	int		i;
	char	**arr;

	i = 0;
	while (env[i])
		i++;
	arr = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (env[++i])
		arr[i] = ft_strdup(env[i]);
	arr[i] = 0;
	return (arr);
}

char	**ft_add_line(char **arr, char *line)
{
	int		i;
	char	**res;

	i = 0;
	while (arr[i])
		i++;
	res = (char **)malloc(sizeof(char *) * (i + 2));
	i = -1;
	while (arr[++i])
		res[i] = ft_strdup(arr[i]);
	res[i++] = ft_strdup(line);
	res[i] = 0;
	free_arr(arr);
	return (res);
}

char	**ft_unset(char **arr, int f)
{
	int		i;
	int		j;
	char	**res;

	i = 0;
	j = 0;
	while (arr[i])
		i++;
	res = (char **)malloc(sizeof(char *) * i);
	i = -1;
	while (arr[++i])
		if (!(i == f))
		{
			res[j] = ft_strdup(arr[i]);
			j++;
		}
	res[j] = 0;
	free_arr(arr);
	return (res);
}
