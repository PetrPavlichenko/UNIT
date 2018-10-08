/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spider.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 12:49:21 by ppavlich          #+#    #+#             */
/*   Updated: 2017/04/13 12:49:29 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	comp_spider(t_frc *frc, int i, int j)
{
	t_spd	spd;
	int		itr;

	spd.z1x = ((j + frc->diff_x * frc->zoom - WIN_X / 2) * \
	frc->side + WIN_X * frc->zx * frc->zoom) / (WIN_X * frc->zoom) + frc->movex;
	spd.z1y = ((i + frc->diff_y * frc->zoom - WIN_Y / 2) * \
	frc->side + WIN_Y * frc->zy * frc->zoom) / (WIN_Y * frc->zoom) + frc->movey;
	spd.c1x = spd.z1x;
	spd.c1y = spd.z1y;
	itr = 0;
	while ((spd.z1x * spd.z1x + spd.z1y * spd.z1y < 4) && itr < frc->iter)
	{
		spd.z2x = spd.z1x;
		spd.z2y = spd.z1y;
		spd.c2x = spd.c1x;
		spd.c2y = spd.c1y;
		spd.z1x = spd.z2x * spd.z2x - spd.z2y * spd.z2y + spd.c1x;
		spd.z1y = 2 * spd.z2x * spd.z2y + spd.c1y;
		spd.c1x = spd.c2x / 2 + spd.z1x;
		spd.c1y = spd.c2y / 2 + spd.z1y;
		itr++;
	}
	if (itr < frc->iter)
		put_pix_to_img(frc, j, i, frc->color * itr);
}

void	spider(t_frc *frc)
{
	int	i;
	int	j;

	i = 0;
	while (i <= WIN_Y)
	{
		j = 0;
		while (j <= WIN_X)
		{
			comp_spider(frc, j, i);
			j++;
		}
		i++;
	}
}
