/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:13:43 by ppavlich          #+#    #+#             */
/*   Updated: 2016/11/29 21:13:47 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *str, const char *str2)
{
	size_t	i;
	int		j;

	j = -1;
	i = ft_strlen(str);
	while (str2[++j] != '\0')
		str[i + j] = str2[j];
	str[i + j] = '\0';
	return (str);
}
