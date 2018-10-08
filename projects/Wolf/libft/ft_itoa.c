/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:03:36 by ppavlich          #+#    #+#             */
/*   Updated: 2016/12/07 16:03:39 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(int n)
{
	int		i;

	i = 1;
	while ((n / 10) != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n = n * (-1);
	}
	i = ft_count(n);
	if ((str = ft_strnew(i + sign)) == NULL)
		return (NULL);
	while (i > 0)
	{
		str[i-- - 1 + sign] = ((n % 10) + 48);
		n /= 10;
	}
	if (sign == 1)
		str[i] = '-';
	return (str);
}
