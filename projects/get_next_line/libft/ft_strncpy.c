/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:39:44 by ppavlich          #+#    #+#             */
/*   Updated: 2016/11/30 14:39:46 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *str, size_t n)
{
	size_t i;

	i = -1;
	while (str[++i] != '\0' && i < n)
		dest[i] = str[i];
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
