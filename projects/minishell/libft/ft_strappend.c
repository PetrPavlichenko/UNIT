/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:16:58 by ppavlich          #+#    #+#             */
/*   Updated: 2017/11/02 21:17:00 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_strappend(char **dest, char *src)
{
	char	*tmp;

	tmp = *dest;
	*dest = ft_strjoin(*dest, src);
	free(tmp);
}
