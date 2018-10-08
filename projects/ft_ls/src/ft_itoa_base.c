/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 19:46:53 by ppavlich          #+#    #+#             */
/*   Updated: 2017/10/21 19:46:58 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	f(long int value, int base, int *i, char *str)
{
	char *s;

	s = "0123456789ABCDEF";
	if (value >= base)
		f(value / base, base, i, str);
	str[(*i)++] = s[value % base];
}

char	*ft_itoa_base(long int value, int base)
{
	char	*str;
	int		i;

	i = 0;
	if (base < 2 || base > 16 || !(str = (char *)malloc(32)))
		return (0);
	if (base == 10 && value < 0)
	{
		str[i] = '-';
		i++;
	}
	if (value < 0)
		value *= (-1);
	f(value, base, &i, str);
	str[i] = '\0';
	return (str);
}
