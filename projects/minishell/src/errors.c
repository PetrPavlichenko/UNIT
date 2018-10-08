/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 20:00:22 by ppavlich          #+#    #+#             */
/*   Updated: 2017/11/12 20:00:25 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error_dir(char *str)
{
	write(2, "minishell:", 10);
	ft_putstr_fd(" No such file or directory: ", 2);
	ft_putendl_fd(str, 2);
}

void	ft_acces_error(char *str)
{
	write(2, "minishell: ", 11);
	ft_putstr_fd("permission denied: ", 2);
	ft_putendl_fd(str, 2);
}

void	chd_error(char *path)
{
	struct stat buff;

	g_r();
	if (!(access(path, F_OK) == 0))
	{
		ft_error_dir(path);
		return ;
	}
	if (!(access(path, R_OK) == 0))
	{
		ft_acces_error(path);
		return ;
	}
	if (stat(path, &buff) == 0)
	{
		(S_ISREG(buff.st_mode)) ? \
		ft_putendl_fd("minishell: Cant open regular file", 2) : 0;
		(S_ISCHR(buff.st_mode)) ? \
		ft_putendl_fd("minishell: Cant open char", 2) : 0;
		(S_ISBLK(buff.st_mode)) ? \
		ft_putendl_fd("minishell:Cant open block", 2) : 0;
		(S_ISSOCK(buff.st_mode)) ? \
		ft_putendl_fd("minishell:Cant open socket", 2) : 0;
	}
	r_g();
}

void	not_found(char *str)
{
	g_r();
	ft_putstr_fd("minishell: comand not found: ", 2);
	ft_putendl_fd(str, 2);
	r_g();
}

void	not_home(void)
{
	g_r();
	ft_putendl_fd("minishell: $OLDPWD not set", 2);
	r_g();
}
