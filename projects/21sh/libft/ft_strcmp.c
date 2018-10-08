/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:34:55 by ppavlich          #+#    #+#             */
/*   Updated: 2016/11/28 18:34:59 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char const *s1, const char *s2)
{
	int				i;
	unsigned char	*s11;
	unsigned char	*s22;

	s11 = (unsigned char *)(s1);
	s22 = (unsigned char *)(s2);
	i = 0;
	while (s11[i] != '\0' && s22[i] != '\0' && s11[i] == s22[i])
		i++;
	return (s11[i] - s22[i]);
}
