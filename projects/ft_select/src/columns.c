/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   columns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:40:43 by ppavlich          #+#    #+#             */
/*   Updated: 2017/12/19 16:40:45 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	chk_winsize(t_term *term)
{
	struct winsize		win;

	ioctl(0, TIOCGWINSZ, &win);
	term->high = win.ws_row;
	term->width = win.ws_col;
}

void		chk_col(t_term *term, char **argv)
{
	int i;
	int cols;

	cols = 0;
	i = 0;
	chk_winsize(term);
	if (term->high < count_lines(term->sel, term))
	{
		while (argv[++i])
			if (term->sel->deleted[i] == '0' && ft_strlen(argv[i]) > \
				(size_t)term->max_len)
				term->max_len = ft_strlen(argv[i]);
		if (term->width > 3)
		{
			cols = ((term->width - 2) / (term->max_len + 2));
			if (cols * term->high < count_lines(term->sel, term))
				term->small = 1;
			term->cols = cols;
		}
	}
	else
		term->cols = 0;
}
