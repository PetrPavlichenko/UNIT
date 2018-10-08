/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:38:28 by ppavlich          #+#    #+#             */
/*   Updated: 2016/11/30 13:39:16 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *str, const char *str2, size_t size)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	while (str[i] != '\0' && i < size)
		i++;
	while (str2[j] != '\0' && (i + j) < (size - 1))
	{
		str[i + j] = str2[j];
		j++;
	}
	if (i < size)
		str[i + j] = '\0';
	return (i + ft_strlen(str2));
}
