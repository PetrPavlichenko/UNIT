/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:04:51 by ppavlich          #+#    #+#             */
/*   Updated: 2017/10/26 18:04:54 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print1(char *str, t_ls *ls, t_lst *t)
{
	if (ls->flag->i == 1)
	{
		ft_putstr(t->ino);
		write(1, " ", 1);
	}
	if (ls->flag->s == 1)
	{
		ft_putstr(t->bl_c);
		write(1, " ", 1);
	}
	ft_putstr(str);
	write(1, "\n", 1);
}

void	print2(char *str)
{
	write(1, "\n", 1);
	ft_putstr(str);
	write(1, ":\n", 2);
}

void	print3(char *str)
{
	ft_putstr(str);
	write(1, ":\n", 2);
}

void	print4(int i)
{
	write(1, "total ", 6);
	ft_putnbr(i);
	write(1, "\n", 1);
}
