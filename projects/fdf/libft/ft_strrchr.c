/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:59:42 by ppavlich          #+#    #+#             */
/*   Updated: 2016/11/29 18:01:36 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int symbol)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (symbol == '\0')
		return ((char*)&str[i]);
	i += 1;
	while (i != 0)
	{
		i--;
		if (str[i] == symbol)
			return ((char*)&str[i]);
	}
	return (NULL);
}
