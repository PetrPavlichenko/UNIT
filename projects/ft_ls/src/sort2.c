/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 17:15:35 by ppavlich          #+#    #+#             */
/*   Updated: 2017/10/21 17:15:37 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_swap_lst(t_lst **lst)
{
	char	t1;
	char	*t2;
	char	*t3;
	char	*t4;
	char	*t5;

	t1 = (*lst)->type_f;
	t2 = (*lst)->name;
	t3 = (*lst)->permshn;
	t4 = (*lst)->links;
	t5 = (*lst)->user;
	(*lst)->type_f = (*lst)->next->type_f;
	(*lst)->name = (*lst)->next->name;
	(*lst)->permshn = (*lst)->next->permshn;
	(*lst)->links = (*lst)->next->links;
	(*lst)->user = (*lst)->next->user;
	(*lst)->next->type_f = t1;
	(*lst)->next->name = t2;
	(*lst)->next->permshn = t3;
	(*lst)->next->links = t4;
	(*lst)->next->user = t5;
	ft_swap_lst2(lst);
	ft_swap_lst3(lst);
}

void	ft_swap_lst2(t_lst **lst)
{
	char	*t1;
	char	*t2;
	char	*t3;
	char	*t4;
	char	*t5;

	t1 = (*lst)->group;
	t2 = (*lst)->size;
	t3 = (*lst)->date;
	t4 = (*lst)->maj;
	t5 = (*lst)->min;
	(*lst)->group = (*lst)->next->group;
	(*lst)->size = (*lst)->next->size;
	(*lst)->date = (*lst)->next->date;
	(*lst)->maj = (*lst)->next->maj;
	(*lst)->min = (*lst)->next->min;
	(*lst)->next->group = t1;
	(*lst)->next->size = t2;
	(*lst)->next->date = t3;
	(*lst)->next->maj = t4;
	(*lst)->next->min = t5;
}

void	ft_swap_lst3(t_lst **lst)
{
	long int	t1;
	time_t		t2;
	long		t3;
	char		*t4;
	char		*t5;

	t1 = (*lst)->bl_s;
	t2 = (*lst)->s_date;
	t3 = (*lst)->s_ns;
	t4 = (*lst)->ino;
	t5 = (*lst)->bl_c;
	(*lst)->bl_s = (*lst)->next->bl_s;
	(*lst)->s_date = (*lst)->next->s_date;
	(*lst)->s_ns = (*lst)->next->s_ns;
	(*lst)->ino = (*lst)->next->ino;
	(*lst)->bl_c = (*lst)->next->bl_c;
	(*lst)->next->bl_s = t1;
	(*lst)->next->s_date = t2;
	(*lst)->next->s_ns = t3;
	(*lst)->next->ino = t4;
	(*lst)->next->bl_c = t5;
}

void	ft_time_sort(t_lst *start)
{
	t_lst	*a;
	int		f;

	f = 1;
	while (f > 0)
	{
		f = 0;
		a = start;
		while (a)
		{
			f = ft_time_help(a, f);
			a = a->next;
		}
	}
}

void	ft_ascii_sort3(t_lst *start)
{
	t_lst	*a;
	int		f;

	f = 1;
	while (f > 0)
	{
		f = 0;
		a = start;
		while (a)
		{
			if (a->next != 0 && ft_strcmp(a->name, a->next->name) > 0 && \
			(a->type_f == 'd' && a->next->type_f == 'd'))
			{
				ft_swap_lst(&a);
				f++;
			}
			a = a->next;
		}
	}
}
