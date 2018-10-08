/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:44:56 by ppavlich          #+#    #+#             */
/*   Updated: 2016/12/01 17:44:58 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst1;
	unsigned char	*src1;

	i = -1;
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	while (++i < n)
		dst1[i] = src1[i];
	return (dst1);
}
