/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:14:26 by ppavlich          #+#    #+#             */
/*   Updated: 2016/11/28 19:14:30 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *big, char const *lit)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (lit[0] == '\0')
		return ((char*)&big[i]);
	while (big[i] != '\0')
	{
		while (lit[j] == big[i + j])
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
