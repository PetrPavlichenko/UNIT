/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:22:47 by ppavlich          #+#    #+#             */
/*   Updated: 2016/11/28 15:22:53 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalnum(int c)
{
	return (((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) || \
	(c >= 48 && c <= 57) ? 1 : 0);
}
