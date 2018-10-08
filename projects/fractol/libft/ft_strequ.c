/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:42:04 by ppavlich          #+#    #+#             */
/*   Updated: 2016/12/03 17:42:07 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int res;

	if (s1 && s2)
	{
		res = ft_strcmp(s1, s2);
		if (res == 0)
			return (1);
		return (0);
	}
	return (0);
}