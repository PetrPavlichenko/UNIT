/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:28:21 by ppavlich          #+#    #+#             */
/*   Updated: 2016/12/05 15:28:24 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	int		i;

	if (s == NULL)
		return (NULL);
	if ((s1 = ft_strnew(len)) == NULL)
		return (NULL);
	i = 0;
	while (len > 0)
	{
		s1[i] = s[start];
		start++;
		i++;
		len--;
	}
	s1[i] = '\0';
	return (s1);
}
