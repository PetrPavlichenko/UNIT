/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:21:16 by ppavlich          #+#    #+#             */
/*   Updated: 2016/11/30 13:23:16 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *str, const char *str2, size_t n)
{
	size_t	i;
	size_t	j;

	j = -1;
	i = ft_strlen(str);
	while (str2[++j] != '\0' && j < n)
		str[i + j] = str2[j];
	str[i + j] = '\0';
	return (str);
}
