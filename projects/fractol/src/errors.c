/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 18:51:27 by ppavlich          #+#    #+#             */
/*   Updated: 2017/04/03 18:51:29 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	name_error(void)
{
	write(1, "Incorrect name of fractal\n", 26);
	write(1, "Chose fractal, press 1 -> julia, 2 -> mandelbrot\n", 49);
	write(1, "3 -> burningship, 4 -> biomorph, 5 -> spider.\n", 44);
	exit(0);
}

void	arg_error(void)
{
	write(1, "Error in the number of arguments\n", 33);
	write(1, "Chose fractal, press 1 -> julia, 2 -> mandelbrot\n", 49);
	write(1, "3->burningship, 4 -> biomorph, 5 -> spider.\n", 44);
	exit(0);
}

void	add_init(t_frc *frc)
{
	frc->iter = 50;
	frc->name == 4 ? (frc->color = 3300) :\
	(frc->color = 1548);
	frc->key.esc = 0;
	frc->zoom = 1.;
	frc->diff_x = 0;
	frc->diff_y = 0;
	frc->zx = 0;
	frc->zy = 0;
	frc->movex = 0;
	frc->movey = 0;
	frc->side = 5;
	frc->key.mouse_on = 0;
	frc->key.zoomp = 0;
	frc->key.zoomm = 0;
}

void	add3_2(t_frc *frc)
{
	if (frc->key.fo == 1)
	{
		frc->name = 4;
		frc->zoom = 1;
	}
	if (frc->key.t == 1)
	{
		frc->name = 3;
		frc->zoom = 1;
	}
	if (frc->key.s == 1)
	{
		frc->name = 2;
		frc->zoom = 1;
	}
	if (frc->key.f == 1)
	{
		frc->name = 1;
		frc->zoom = 1;
	}
	if (frc->key.fi == 1)
	{
		frc->name = 5;
		frc->zoom = 1;
	}
}

void	ft_str_view(t_frc *frc)
{
	mlx_string_put(frc->mlx, frc->win, 20, 20, 16724787, \
		"Change iterations ( )");
	mlx_string_put(frc->mlx, frc->win, 20, 40, 16724787, \
		"Press for move WASD");
	mlx_string_put(frc->mlx, frc->win, 20, 60, 16724787, \
		"Change zoom value - +");
	mlx_string_put(frc->mlx, frc->win, 20, 80, 16724787, \
		"Change color { }");
	mlx_string_put(frc->mlx, frc->win, 20, 100, 16724787, \
		"Change difined color 1,2,3,4,5");
	mlx_string_put(frc->mlx, frc->win, 20, 120, 16724787, \
		"Change fractal NUM1,2,3,4,5");
}
