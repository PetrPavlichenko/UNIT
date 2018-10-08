/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 02:57:26 by ppavlich          #+#    #+#             */
/*   Updated: 2017/11/11 02:57:30 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	norm_main(char *s, char ***env)
{
	char	**arr;
	char	**arr3;
	int		i;

	i = -1;
	arr3 = ft_strsplit(s, ';');
	while (arr3[++i])
	{
		arr = splitspaces(arr3[i]);
		check_command(arr, env);
		free_arr(arr);
	}
	free_arr(arr3);
}

int		main(int argc, char **argv, char **env)
{
	char	*s;
	char	**arr2;
	char	*pwd;

	if (argc && argv && env)
		;
	signal(2, SIG_IGN);
	arr2 = alloc_env(env);
	while (1)
	{
		ft_putstr(GREEN);
		if (ft_strlen(pwd = ft_getpwd_m()) <= 2)
			ft_putstr("$>");
		else
			ft_putstr(pwd);
		ft_putstr(RESET);
		if ((get_next_line(0, &s)) < 1)
			continue ;
		norm_main(s, &arr2);
		s == NULL ? 0 : free(s);
		pwd == NULL ? 0 : free(pwd);
	}
	arr2 ? free_arr(arr2) : 0;
	return (0);
}
