/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 00:36:29 by ppavlich          #+#    #+#             */
/*   Updated: 2017/12/10 00:36:31 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		count_lines(t_selct *sel, t_term *term)
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
		;
	return (j);
}

void	ft_clear(void)
{
	char	*str;

	ft_putstr_fd(tgetstr("cl", NULL), 1);
	str = tgetstr("cm", NULL);
	str = tgoto(str, 0, 0);
	ft_putstr_fd(str, 1);
}

void	clear_outp(t_selct *sel, int fd, t_term *term)
{
	char	*str;
	int		i;

	i = -1;
	while (++i <= (term->cols == 0 ? count_lines(sel, term) : \
		count_lines_for_c(sel, term)))
	{
		str = tgetstr("cm", NULL);
		str = tgoto(str, i, 0);
		ft_putstr_fd(str, fd);
		str = tgetstr("dl", NULL);
		ft_putstr_fd(str, fd);
	}
	str = tgetstr("cm", NULL);
	str = tgoto(str, 0, 0);
	ft_putstr_fd(str, fd);
	ft_putstr_fd(tgetstr("cl", NULL), 1);
	term->is_print = 0;
}

void	return_outp(t_selct *sel, char **arr, int fd, t_term *term)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	clear_outp(sel, fd, term);
	while (arr[++i])
		if (sel->selected[i] == 49 && sel->deleted[i] == 48)
		{
			if (f == 0)
			{
				f++;
				ft_putstr(arr[i]);
			}
			else
			{
				write(1, " ", 1);
				ft_putstr(arr[i]);
			}
		}
	if (f == 1)
		write(1, "\n", 1);
	ft_putstr(tgetstr("ve", NULL));
	exit(1);
}

void	exit_func(t_selct *sel, int fd, t_term *term)
{
	clear_outp(sel, fd, term);
	reset_keypress(term);
	exit(1);
}
