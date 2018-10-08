/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:46:46 by ppavlich          #+#    #+#             */
/*   Updated: 2017/10/26 17:46:49 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	calc_space(t_lst *lst)
{
	t_lst	*tmp;
	size_t	i;
	char	*str;
	char	*t;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		i < ft_strlen(tmp->size) ? i = ft_strlen(tmp->size) : 0;
		tmp = tmp->next;
	}
	tmp = lst;
	while (tmp)
	{
		if (i > ft_strlen(tmp->size))
		{
			ft_memset(str = ft_strnew(i), ' ', i);
			t = str + (i - ft_strlen(tmp->size));
			t = ft_memmove(t, tmp->size, ft_strlen(tmp->size));
			tmp->size = str;
		}
		tmp = tmp->next;
	}
}

void	calc_space2(t_lst *lst)
{
	t_lst	*tmp;
	size_t	i;
	char	*str;
	char	*t;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		i < ft_strlen(tmp->links) ? i = ft_strlen(tmp->links) : 0;
		tmp = tmp->next;
	}
	tmp = lst;
	while (tmp)
	{
		if (i > ft_strlen(tmp->links))
		{
			ft_memset(str = ft_strnew(i), ' ', i);
			t = str + (i - ft_strlen(tmp->links));
			t = ft_memmove(t, tmp->links, ft_strlen(tmp->links));
			tmp->links = str;
		}
		tmp = tmp->next;
	}
}

void	calc_space3(t_lst *lst)
{
	t_lst	*tmp;
	size_t	i;
	char	*str;
	char	*t;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		i < ft_strlen(tmp->user) ? i = ft_strlen(tmp->user) : 0;
		tmp = tmp->next;
	}
	tmp = lst;
	while (tmp)
	{
		if (i > ft_strlen(tmp->user))
		{
			ft_memset(str = ft_strnew(i), ' ', i);
			t = str + (i - ft_strlen(tmp->user));
			t = ft_memmove(t, tmp->user, ft_strlen(tmp->user));
			tmp->user = str;
		}
		tmp = tmp->next;
	}
}

void	calc_space4(t_lst *lst)
{
	t_lst	*tmp;
	size_t	i;
	char	*str;
	char	*t;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		i < ft_strlen(tmp->group) ? i = ft_strlen(tmp->group) : 0;
		tmp = tmp->next;
	}
	tmp = lst;
	while (tmp)
	{
		if (i > ft_strlen(tmp->group))
		{
			ft_memset(str = ft_strnew(i), ' ', i);
			t = str + (i - ft_strlen(tmp->group));
			t = ft_memmove(t, tmp->group, ft_strlen(tmp->group));
			tmp->group = str;
		}
		tmp = tmp->next;
	}
}

void	calc_l_space(t_lst *lst)
{
	calc_space(lst);
	calc_space2(lst);
	calc_space3(lst);
	calc_space4(lst);
	calc_space5(lst);
}
