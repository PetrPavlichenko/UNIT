/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:33:30 by ppavlich          #+#    #+#             */
/*   Updated: 2017/11/23 11:33:35 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	g_r(void)
{
	ft_putstr(RED);
}

void	r_g(void)
{
	ft_putstr(RESETR);
}

void	ft_opwd(char ***env, char *pwd)
{
	char *s;
	char **inp;

	s = ft_strjoin("OLDPWD=", pwd);
	inp = (char **)malloc(sizeof(char *) * 3);
	inp[0] = ft_strdup("setenv");
	inp[1] = s;
	inp[2] = 0;
	ft_setenv(inp, env);
	free(pwd);
	free_arr(inp);
}

void	ft_putstr_echo(char const *s)
{
	int i;

	if (s)
	{
		i = -1;
		while (s[++i] != '\0')
			if (s[i] != 34 && s[i] != 39)
				write(1, &s[i], 1);
	}
}

char	*ft_getpwd_m(void)
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
	ft_strappend(&buff, "$>");
	return (buff);
}
