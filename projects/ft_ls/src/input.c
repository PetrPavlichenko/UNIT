/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:07:28 by ppavlich          #+#    #+#             */
/*   Updated: 2017/10/27 18:07:31 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		check_dir_and_file(char **inp)
{
	int i;

	i = 1;
	while (inp[i])
	{
		if (inp[i][0] != '-' || (inp[i][0] == '-' && inp[i][1] == '\0'))
			return (1);
		i++;
	}
	return (0);
}

char	**rewrite_inp(char **inp)
{
	char	**new;
	int		i;

	i = 0;
	while (inp[i])
		i++;
	new = (char **)malloc(sizeof(char *) * i + 2);
	i = 0;
	while (inp[i])
	{
		new[i] = (char *)malloc(ft_strlen(inp[i]) + 1);
		i++;
	}
	new[i] = (char *)malloc(2);
	i = 0;
	while (inp[i])
	{
		new[i] = ft_memcpy(new[i], inp[i], (ft_strlen(inp[i]) + 1));
		i++;
	}
	new[i][0] = '.';
	new[i++][1] = '\0';
	new[i] = NULL;
	return (new);
}

char	**alloc_2d_arr(int i, int j)
{
	char	**new;
	int		y;

	y = 0;
	new = (char **)malloc(sizeof(char *) * i + 1);
	while (y <= i)
	{
		new[y] = (char *)malloc(j + 1);
		ft_bzero(new[y], j + 1);
		y++;
	}
	new[y] = NULL;
	return (new);
}
