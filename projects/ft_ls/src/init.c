/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 18:56:59 by ppavlich          #+#    #+#             */
/*   Updated: 2017/10/06 18:57:03 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_init(t_ls *ls)
{
	ls->start = 0;
	ls->first = 0;
	ls->flag->t = 0;
	ls->flag->rb = 0;
	ls->flag->r = 0;
	ls->flag->l = 0;
	ls->flag->a = 0;
	ls->flag->i = 0;
	ls->flag->s = 0;
}

int		ft_chk_err(t_lst *lst)
{
	while (lst)
	{
		if (lst->type_f == 'g')
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	ft_sort(t_ls *ls, t_lst **lst, int i)
{
	if (i == 1)
	{
		ft_ascii_sort(*lst);
		if (ls->flag->t == 1)
			ft_time_sort(*lst);
		if (ls->flag->r == 1)
			ft_reverse_list(lst);
		ft_sort_type(*lst);
		ft_chk_err(*lst) ? ft_ascii_sort3(*lst) : 0;
		ft_sort_error(*lst);
		ls->flag->l == 1 ? calc_l_space(*lst) : 0;
	}
	if (i == 2)
	{
		ft_ascii_sort(*lst);
		if (ls->flag->t == 1)
			ft_time_sort(*lst);
		if (ls->flag->r == 1)
			ft_reverse_list(lst);
		ft_sort_error(*lst);
		(ls->flag->l == 1 || ls->flag->s == 1) ? calc_l_space(*lst) : 0;
	}
}

void	ft_del_lst(t_lst **lst)
{
	t_lst *tmp;
	t_lst *tmp2;

	tmp = *lst;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	tmp = NULL;
	tmp2 = NULL;
}
