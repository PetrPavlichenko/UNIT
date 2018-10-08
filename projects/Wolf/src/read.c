/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 18:31:23 by ppavlich          #+#    #+#             */
/*   Updated: 2017/08/31 18:31:48 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_reading(t_w *w, char *file)
{
	char	str[1176];
	int		i;

	if ((w->fd = open(file, O_RDONLY)) == (-1))
		perror("Open map error");
	i = read(w->fd, str, 1176);
	w->all.map = ft_strsplit(str, '\n');
	i = 0;
	while (i < 24)
	{
		printf("%s\n", w->all.map[i]);
		i++;
	}
}
