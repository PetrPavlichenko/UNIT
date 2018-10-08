/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 20:51:24 by ppavlich          #+#    #+#             */
/*   Updated: 2017/10/02 20:51:33 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_error_flag(char c)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	write(2, &c, 1);
	write(2, "\n", 1);
	ft_putstr_fd("usage: ft_ls [-Rartils] [file ...]\n", 2);
	exit(1);
}

void		ft_error_dir(char *str)
{
	write(2, "ft_ls: ", 7);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

long int	count_total(t_lst *lst)
{
	long int i;

	i = 0;
	while (lst)
	{
		i += lst->bl_s;
		lst = lst->next;
	}
	return (i);
}

int			ft_time_help(t_lst *a, int f)
{
	if (a->next != 0 && a->s_date <= a->next->s_date)
	{
		if (a->s_date < a->next->s_date)
		{
			ft_swap_lst(&a);
			f++;
		}
		else if (a->s_date == a->next->s_date && a->s_ns < a->next->s_ns)
		{
			ft_swap_lst(&a);
			f++;
		}
	}
	return (f);
}

void		print_link(t_lst *lst, char *path)
{
	char *buff;

	buff = ft_strnew(1024);
	readlink(path, buff, 1024);
	ft_putstr(lst->name);
	write(1, " -> ", 4);
	ft_putstr(buff);
	free(buff);
}
