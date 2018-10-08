/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:08:03 by ppavlich          #+#    #+#             */
/*   Updated: 2016/12/03 16:08:06 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*s1;

	if (s && f)
	{
		if ((s1 = ft_strnew(ft_strlen(s))) == NULL)
			return (NULL);
		i = -1;
		while (s[++i] != '\0')
			s1[i] = f((char)s[i]);
		return (s1);
	}
	return (NULL);
}
