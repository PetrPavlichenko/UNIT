/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:13:15 by ppavlich          #+#    #+#             */
/*   Updated: 2016/11/30 18:13:19 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;

	i = -1;
	s1 = (unsigned char *)s;
	while (++i < n)
	{
		if (s1[i] == (unsigned char)c)
			return (&s1[i]);
	}
	return (NULL);
}
