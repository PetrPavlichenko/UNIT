/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:46:04 by ppavlich          #+#    #+#             */
/*   Updated: 2016/11/30 16:46:06 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char	*s1buff;
	unsigned const char	*s2buff;

	i = -1;
	s1buff = s1;
	s2buff = s2;
	while (++i < n)
	{
		if (s1buff[i] != s2buff[i])
			return (s1buff[i] - s2buff[i]);
	}
	return (0);
}
