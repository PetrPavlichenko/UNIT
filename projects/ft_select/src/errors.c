/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:39:28 by ppavlich          #+#    #+#             */
/*   Updated: 2017/11/26 16:39:33 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	term_err(void)
{
	ft_putendl_fd("An error occured", 2);
	exit(-1);
}

void	arg_err(void)
{
	ft_putendl_fd("Please run program with arguments", 2);
	exit(-1);
}

int		count_lines_for_c(t_selct *sel, t_term *term)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++i <= sel->count_files)
	{
		if (sel->deleted[i] == '0')
			j++;
	}
	if (term->cols == 0)
		return (j);
	else
		return (j / term->cols);
}
