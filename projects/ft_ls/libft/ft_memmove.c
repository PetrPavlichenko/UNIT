/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:40:53 by ppavlich          #+#    #+#             */
/*   Updated: 2016/12/01 18:40:56 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*newdst;
	unsigned char		*newsrc;
	size_t				i;

	newdst = (unsigned char*)dst;
	newsrc = (unsigned char*)src;
	i = 0;
	if (newdst < newsrc)
	{
		while (len-- != 0)
		{
			newdst[i] = newsrc[i];
			i++;
		}
	}
	if (newdst > newsrc)
	{
		while (len-- != 0)
			newdst[len] = newsrc[len];
	}
	return (dst);
}
