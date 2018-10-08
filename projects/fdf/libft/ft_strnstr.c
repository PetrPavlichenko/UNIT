/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:17:48 by ppavlich          #+#    #+#             */
/*   Updated: 2016/11/28 19:17:50 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *big, char const *lit, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (lit[0] == '\0')
		return ((char*)&big[i]);
	while (big[i] != '\0' && i < len)
	{
		while (lit[j] == big[i + j] && (i + j) < len)
		{
			j++;
			if (lit[j] == '\0')
				return ((char*)&big[i]);
		}
		i++;
		j = 0;
	}
	return (NULL);
}
