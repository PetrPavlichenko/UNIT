/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 14:24:55 by ppavlich          #+#    #+#             */
/*   Updated: 2017/12/19 14:24:58 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		len_b(t_selct *sel, int f)
{
	int i;

	if (f == 0)
	{
		i = 0;
		while (++i < sel->count_files)
			if (sel->deleted[i] == '0')
				return (i);
	}
	else if (f == 1)
	{
		i = sel->count_files + 1;
		while (--i > 0)
			if (sel->deleted[i] == '0')
				return (i);
	}
	return (-1);
}

void			circle_inp(t_selct *sel, int f)
{
	if (f == 1)
	{
		if (sel->cur_file == len_b(sel, 1))
			sel->cur_file = len_b(sel, 0);
		else
			while (sel->cur_file < len_b(sel, 1))
			{
				sel->cur_file += 1;
				if (sel->deleted[sel->cur_file] == '0')
					break ;
			}
	}
	if (f == 0)
	{
		if (sel->cur_file == len_b(sel, 0))
			sel->cur_file = len_b(sel, 1);
		else
			while (sel->cur_file > len_b(sel, 0))
			{
				sel->cur_file -= 1;
				if (sel->deleted[sel->cur_file] == '0')
					break ;
			}
	}
}

void			ft_delete(t_selct *sel)
{
	sel->deleted[sel->cur_file] = '1';
	if (sel->cur_file >= len_b(sel, 1))
		sel->cur_file = len_b(sel, 1);
	else if (sel->cur_file <= len_b(sel, 0))
		sel->cur_file = len_b(sel, 0);
	else
		circle_inp(sel, 1);
}
