/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:00:05 by ppavlich          #+#    #+#             */
/*   Updated: 2016/12/03 17:00:08 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s1;

	if (s && f)
	{
		if ((s1 = ft_strnew(ft_strlen(s))) == NULL)
			return (NULL);
		i = -1;
		while (s[++i] != '\0')
			s1[i] = f(i, (char)s[i]);
		return (s1);
	}
	return (NULL);
}
