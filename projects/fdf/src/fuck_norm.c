/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuck_norm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 01:37:59 by ppavlich          #+#    #+#             */
/*   Updated: 2017/03/29 01:38:02 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fuck_norm(int key, t_fdf *fdf)
{
	if (key == 11)
		fdf->vint = 0;
	if (key == 9)
		fdf->vint = 1;
	if (key == 18)
		fdf->flag.r1 = 1;
	if (key == 19)
		fdf->flag.g2 = 1;
	if (key == 20)
		fdf->flag.b3 = 1;
	if (key == 21)
		fdf->flag.k4 = 1;
	if (key == 33)
		fdf->flag.zoom_min = 1;
	if (key == 30)
		fdf->flag.zoom_plus = 1;
	if (key == 27)
		fdf->flag.z_minus = 1;
	if (key == 24)
		fdf->flag.z_plus = 1;
}

void	ft_fuck_norm2(int key, t_fdf *fdf)
{
	if (key == 18)
		fdf->flag.r1 = 0;
	if (key == 19)
		fdf->flag.g2 = 0;
	if (key == 20)
		fdf->flag.b3 = 0;
	if (key == 21)
		fdf->flag.k4 = 0;
	if (key == 33)
		fdf->flag.zoom_min = 0;
	if (key == 30)
		fdf->flag.zoom_plus = 0;
	if (key == 27)
		fdf->flag.z_minus = 0;
	if (key == 24)
		fdf->flag.z_plus = 0;
}

void	ft_fuck_norm3(t_fdf *fdf)
{
	if (fdf->flag.r1 == 1)
		fdf->clr = 1;
	if (fdf->flag.g2 == 1)
		fdf->clr = 2;
	if (fdf->flag.b3 == 1)
		fdf->clr = 3;
	if (fdf->flag.k4 == 1)
		fdf->clr = 4;
	if (fdf->flag.zoom_plus == 1 && fdf->zoom < 10)
		fdf->zoom += 0.1;
	if (fdf->flag.zoom_min == 1 && fdf->zoom > 0.1)
		fdf->zoom -= 0.1;
	if (fdf->flag.z_minus == 1)
		fdf->z3 -= 0.05;
	if (fdf->flag.z_plus == 1)
		fdf->z3 += 0.05;
}

int		ft_colr(t_fdf *fdf, int i, int j)
{
	if (fdf->clr == 1)
		return (fdf->map[i][j]->red);
	if (fdf->clr == 2)
		return (fdf->map[i][j]->green);
	if (fdf->clr == 3)
		return (fdf->map[i][j]->blue);
	if (fdf->clr == 4)
		return (fdf->map[i][j]->color);
	return (0);
}

void	ft_main_str(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 100, 100, 16724787, \
		"Arrows for rotate -> <-");
	mlx_string_put(fdf->mlx, fdf->win, 100, 120, 16724787, \
		"Press for move WASD");
	mlx_string_put(fdf->mlx, fdf->win, 100, 140, 16724787, \
		"Change scale { }");
	mlx_string_put(fdf->mlx, fdf->win, 100, 160, 16724787, \
		"Change altitude - +");
	mlx_string_put(fdf->mlx, fdf->win, 100, 180, 16724787, \
		"Change color 1,2,3,4");
	mlx_string_put(fdf->mlx, fdf->win, 100, 200, 16724787, \
		"Change vizualization type v , b");
}
