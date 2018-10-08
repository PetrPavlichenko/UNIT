/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biomorph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:16:07 by ppavlich          #+#    #+#             */
/*   Updated: 2017/04/12 20:16:10 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	comp_bio(t_frc *frc, int i, int j)
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
	while ((x * x) < 70 && (y * y) < 70 && itr < frc->iter)
	{
		x2 = x;
		x = pow(x2, 4) + pow(y, 4) - 6 * x * x * y * y + 1.;
		y = 4 * pow(x2, 3) * y - 4 * x2 * pow(y, 3) + 1.01828;
		itr++;
	}
	if (fabs(x) > 10 * frc->iter / 50 || fabs(y) > 1000 * frc->iter / 50)
		put_pix_to_img(frc, j, i, frc->color * itr);
}

void	biomorph(t_frc *frc)
{
	int	i;
	int	j;

	i = 0;
	while (i <= WIN_Y)
	{
		j = 0;
		while (j <= WIN_X)
		{
			comp_bio(frc, j, i);
			j++;
		}
		i++;
	}
}
