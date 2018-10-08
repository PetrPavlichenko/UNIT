/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 19:26:40 by ppavlich          #+#    #+#             */
/*   Updated: 2017/10/13 19:26:43 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ascii_sort(t_lst *start)
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
			if (a->next != 0 && ft_strcmp(a->name, a->next->name) > 0)
			{
				ft_swap_lst(&a);
				f++;
			}
			a = a->next;
		}
	}
}

void	ft_sort_error(t_lst *start)
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
			if (a->next != 0 && ((a->type_f != 'g' && a->next->type_f == 'g')))
			{
				ft_swap_lst(&a);
				f++;
			}
			a = a->next;
		}
	}
}

void	ft_sort_type(t_lst *start)
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
			if (a->next != 0 && (a->type_f == 'd' && a->next->type_f != 'd'))
			{
				ft_swap_lst(&a);
				f++;
			}
			a = a->next;
		}
	}
}

void	ft_reverse_list(t_lst **alst)
{
	t_lst	*new;
	t_lst	*old_next;
	t_lst	*old_current;

	new = 0;
	old_current = *alst;
	while (old_current)
	{
		old_next = old_current->next;
		old_current->next = new;
		new = old_current;
		old_current = old_next;
	}
	*alst = new;
}
