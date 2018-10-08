/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_space2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:13:24 by ppavlich          #+#    #+#             */
/*   Updated: 2017/11/06 19:13:28 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	calc_space5(t_lst *lst)
{
	t_lst	*tmp;
	size_t	i;
	char	*str;
	char	*t;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		i < ft_strlen(tmp->bl_c) ? i = ft_strlen(tmp->bl_c) : 0;
		tmp = tmp->next;
	}
	tmp = lst;
	while (tmp)
	{
		if (i > ft_strlen(tmp->bl_c))
		{
			ft_memset(str = ft_strnew(i), ' ', i);
			t = str + (i - ft_strlen(tmp->bl_c));
			t = ft_memmove(t, tmp->bl_c, ft_strlen(tmp->bl_c));
			tmp->bl_c = str;
		}
		tmp = tmp->next;
	}
}
