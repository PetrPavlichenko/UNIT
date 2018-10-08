/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:15:44 by ppavlich          #+#    #+#             */
/*   Updated: 2017/03/28 17:15:49 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_base_symb(char c, int base, char letter)
{
	if (base <= 10 && c >= '0' && c <= '9')
		return (1);
	if ((c >= '0' && c <= '9') || (c >= letter && c <= (letter + base - 10)))
		return (1);
	return (0);
}

static int	check_letter(char *str, int base, int i)
{
	while (str[++i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'A' + base)
			return (1);
		if (str[i] >= 'a' && str[i] <= 'a' + base)
			return (0);
		i++;
	}
	return (1);
}

int			ft_atoi_base(char *str, int base)
{
	int		res;
	int		i;
	int		sign;
	char	letter;

	res = 0;
	i = 0;
	if (base < 2 || base > 16)
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	letter = check_letter(str, base, i) ? 'A' : 'a';
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_base_symb(str[i], base, letter))
	{
		if (str[i] - letter >= 0)
			res = res * base + (str[i] - letter + 10);
		else
			res = res * base + (str[i] - 48);
		i++;
	}
	return (res * sign);
}
