/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:20:08 by ppavlich          #+#    #+#             */
/*   Updated: 2017/03/28 17:20:12 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_count_x_y(t_fdf *fdf, int i, int j)
{
	double b;
	double a;
	double c;

	a = fdf->h * 0.0175433;
	b = fdf->v * 0.0175433;
	c = fdf->z * 0.0175433;
	fdf->map[i][j]->x_n = ((fdf->map[i][j]->x * cos(b) + (-fdf->map[i][j]->y\
	* sin(a) + fdf->map[i][j]->z * fdf->z3 * cos(a)) * sin(b)) * cos(c) + \
	(fdf->map[i][j]->y * cos(a) + fdf->map[i][j]->z * fdf->z3 * sin(a))\
	* sin(c));
	fdf->map[i][j]->y_n = (-(fdf->map[i][j]->x * cos(b) + \
	(-fdf->map[i][j]->y * sin(a) + fdf->map[i][j]->z * fdf->z3 * cos(a))\
	* sin(b)) * sin(c) + (fdf->map[i][j]->y * cos(a) + fdf->map[i][j]->z\
	* fdf->z3 * sin(a)) * cos(c));
	if (fdf->vint == 1)
	{
		fdf->map[i][j]->x_n = (int)fdf->map[i][j]->x_n;
		fdf->map[i][j]->y_n = (int)fdf->map[i][j]->y_n;
	}
}

void			brezen_alhor(t_fdf *fdf, int i, int j)
{
	fdf->del_x = abs(fdf->crd.x1 - fdf->crd.x0);
	fdf->del_y = abs(fdf->crd.y1 - fdf->crd.y0);
	fdf->crd.signx = fdf->crd.x1 >= fdf->crd.x0 ? 1 : -1;
	fdf->crd.signy = fdf->crd.y1 >= fdf->crd.y0 ? 1 : -1;
	fdf->error = fdf->del_x - fdf->del_y;
	mlx_pixel_put(fdf->mlx, fdf->win, fdf->crd.x0, fdf->crd.y0, \
		fdf->clr == 0 ? fdf->map[i][j]->color : ft_colr(fdf, i, j));
	while (fdf->crd.x0 != fdf->crd.x1 || fdf->crd.y0 != fdf->crd.y1)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->crd.x0, fdf->crd.y0, \
			fdf->clr == 0 ? fdf->map[i][j]->color : ft_colr(fdf, i, j));
		fdf->error2 = fdf->error * 2;
		if (fdf->error2 > -(fdf->del_y))
		{
			fdf->error -= fdf->del_y;
			fdf->crd.x0 += fdf->crd.signx;
		}
		if (fdf->error2 < fdf->del_x)
		{
			fdf->error += fdf->del_x;
			fdf->crd.y0 += fdf->crd.signy;
		}
	}
}

static void		ft_support(t_fdf *fdf, int i, int j, int f)
{
	if (f == 1)
	{
		fdf->crd.x0 = fdf->map[i][j]->x_n * (fdf->dist_x / fdf->zoom) + fdf->x2;
		fdf->crd.x1 = fdf->map[i][j + 1]->x_n * (fdf->dist_x / fdf->zoom)\
		+ fdf->x2;
		fdf->crd.y0 = fdf->map[i][j]->y_n * (fdf->dist_x / fdf->zoom) + fdf->y2;
		fdf->crd.y1 = fdf->map[i][j + 1]->y_n * (fdf->dist_x / fdf->zoom)\
		+ fdf->y2;
	}
	if (f == 2)
	{
		fdf->crd.x0 = fdf->map[i][j]->x_n * (fdf->dist_x / fdf->zoom) + fdf->x2;
		fdf->crd.x1 = fdf->map[i + 1][j]->x_n * (fdf->dist_x / fdf->zoom)\
		+ fdf->x2;
		fdf->crd.y0 = fdf->map[i][j]->y_n * (fdf->dist_x / fdf->zoom) + fdf->y2;
		fdf->crd.y1 = fdf->map[i + 1][j]->y_n * (fdf->dist_x / fdf->zoom)\
		+ fdf->y2;
	}
}

void			ft_draw(t_fdf *fdf)
{
	int		i;
	int		j;

	i = -1;
	while (++i <= (fdf->m_y - 1))
	{
		j = 0;
		while (j < fdf->m_x)
		{
			ft_count_x_y(fdf, i, j);
			if (j < fdf->m_x - 1)
			{
				ft_count_x_y(fdf, i, j + 1);
				ft_support(fdf, i, j, 1);
				brezen_alhor(fdf, i, j);
			}
			if (i < (fdf->m_y - 1))
			{
				ft_count_x_y(fdf, i + 1, j);
				ft_support(fdf, i, j, 2);
				brezen_alhor(fdf, i, j);
			}
			j++;
		}
	}
}
