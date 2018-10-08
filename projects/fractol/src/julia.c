/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 17:27:41 by ppavlich          #+#    #+#             */
/*   Updated: 2017/04/09 17:27:43 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_move(int x, int y, t_frc *frc)
{
	if (frc->key.mouse_on == 1)
	{
		frc->jx = (x - (WIN_X / 2)) / ((WIN_X * frc->zoom) / 1.5);
		frc->jy = (y - (WIN_Y / 2)) / ((WIN_Y * frc->zoom) / 1.5);
	}
	return (0);
}

void	comp_julia(t_frc *frc, int i, int j)
{
	double	x;
	double	y;
	double	x2;
	int		itr;

	x = ((j + frc->diff_x * frc->zoom - WIN_X / 2) * \
			frc->side + WIN_X * frc->zx * frc->zoom) / (WIN_X * frc->zoom)\
			+ frc->movex;
	y = ((i + frc->diff_y * frc->zoom - WIN_Y / 2) * \
			frc->side + WIN_Y * frc->zy * frc->zoom) / (WIN_Y * frc->zoom)\
			+ frc->movey;
	itr = 0;
	while ((x * x + y * y < 4) && itr < frc->iter)
	{
		x2 = x;
		x = x2 * x2 - y * y + frc->jx;
		y = 2 * x2 * y - frc->jy;
		itr++;
	}
	if (itr < frc->iter)
		put_pix_to_img(frc, j, i, frc->color * itr);
}

void	julia(t_frc *frc)
{
	int	i;
	int	j;

	i = 0;
	while (i <= WIN_Y)
	{
		j = 0;
		while (j <= WIN_X)
		{
			comp_julia(frc, j, i);
			j++;
		}
		i++;
	}
}
