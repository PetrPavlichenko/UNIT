/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:19:09 by ppavlich          #+#    #+#             */
/*   Updated: 2017/04/11 16:19:19 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	comp_bur(t_frc *frc, int i, int j)
{
	double	x;
	double	y;
	double	x2;
	int		itr;

	x = 0;
	y = 0;
	itr = 0;
	while ((x * x + y * y < 4) && itr < frc->iter)
	{
		x2 = x;
		x = x2 * x2 - y * y + ((j + frc->diff_x * frc->zoom - WIN_X / 2) * \
			frc->side + WIN_X * frc->zx * frc->zoom) / (WIN_X * frc->zoom)\
			+ frc->movex;
		y = fabs(2 * x2 * y) + ((i + frc->diff_y * frc->zoom - WIN_Y / 2) * \
			frc->side + WIN_Y * frc->zy * frc->zoom) / (WIN_Y * frc->zoom)\
			+ frc->movey;
		itr++;
	}
	if (itr < frc->iter)
		put_pix_to_img(frc, j, i, frc->color * itr);
}

void	burningship(t_frc *frc)
{
	int	i;
	int	j;

	i = 0;
	while (i <= WIN_Y)
	{
		j = 0;
		while (j <= WIN_X)
		{
			comp_bur(frc, i, j);
			j++;
		}
		i++;
	}
}
