/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 20:02:09 by ppavlich          #+#    #+#             */
/*   Updated: 2016/12/02 20:02:13 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char *s;

	s = (unsigned char*)malloc(sizeof(unsigned char) * size);
	if (s != NULL)
	{
		ft_bzero(s, size);
		return (s);
	}
	return (NULL);
}
