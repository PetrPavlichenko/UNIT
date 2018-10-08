/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 12:19:59 by ppavlich          #+#    #+#             */
/*   Updated: 2017/12/07 12:20:01 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static char	*set_select(int i)
{
	int		j;
	char	*str;

	j = -1;
	str = (char *)malloc(sizeof(i));
	while (++j < i)
		str[j] = '0';
	str[j] = '\0';
	return (str);
}

static void	ft_print_cols(char *str, int fd, t_term *term)
{
	int i;

	i = 0;
	ft_putstr_fd(str, fd);
	i = ft_strlen(str);
	while (i < (term->max_len + 1))
	{
		ft_putstr_fd(tgetstr("nd", NULL), 1);
		i++;
	}
	(term->cur_col)++;
	if (term->cur_col == term->cols)
	{
		write(fd, "\n", 1);
		term->cur_col = 1;
	}
}

void		print_arr(t_selct *sel, char **arr, int fd, t_term *term)
{
	int	i;

	i = 0;
	ft_putstr_fd(tgetstr("cl", NULL), 1);
	if (term->is_print == 1)
		return ;
	while (arr[++i])
	{
		if (sel->deleted[i] == 49)
			continue ;
		(sel->selected[i] == 49) ? ft_putstr_fd("\033[7m", fd) : 0;
		if (i == sel->cur_file)
		{
			ft_putstr_fd("\033[4m", fd);
			(term->cols > 0) ? ft_print_cols(arr[i], fd, term) : \
			ft_putendl_fd(arr[i], fd);
			ft_putstr_fd("\033[24m", fd);
		}
		else
			(term->cols > 0) ? ft_print_cols(arr[i], fd, term) : \
			ft_putendl_fd(arr[i], fd);
		(sel->selected[i] == 49) ? ft_putstr_fd("\033[27m", fd) : 0;
	}
	term->is_print = 1;
	term->cur_col = 0;
}

t_selct		*set_input(char **arr)
{
	int		i;
	t_selct	*sel;

	i = 0;
	sel = (t_selct *)malloc(sizeof(t_selct));
	sel->cur_file = 1;
	while (arr[i])
		i++;
	sel->count_files = i - 1;
	sel->selected = set_select(i);
	sel->deleted = ft_strdup(sel->selected);
	return (sel);
}
