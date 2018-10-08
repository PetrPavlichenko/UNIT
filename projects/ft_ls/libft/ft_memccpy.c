/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:06:26 by ppavlich          #+#    #+#             */
/*   Updated: 2016/12/01 18:06:39 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst1;
	unsigned char	*src1;

	i = -1;
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	while (++i < n)
	{
		dst1[i] = src1[i];
		if (dst1[i] == (unsigned char)c)
			return (&dst1[++i]);
	}
	return (NULL);
}
