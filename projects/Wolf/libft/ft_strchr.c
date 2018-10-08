/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:06:28 by ppavlich          #+#    #+#             */
/*   Updated: 2016/11/29 21:06:32 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int symbol)
{
	size_t i;

	i = -1;
	while (str[++i] != '\0')
		;
	if (symbol == '\0')
		return ((char*)&str[i]);
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == symbol)
			return ((char*)&str[i]);
	}
	return (NULL);
}
