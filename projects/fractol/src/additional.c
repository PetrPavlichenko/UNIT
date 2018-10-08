/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 20:49:34 by ppavlich          #+#    #+#             */
/*   Updated: 2017/04/07 20:49:41 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pix_to_img(t_frc *frc, int x, int y, int color)
{
	if (x > 0 && x < WIN_X && y > 0 && y < WIN_Y)
	{
		color = mlx_get_color_value(frc->mlx, color);
		ft_memcpy(frc->img_ptr + y * WIN_X * 4 + x * 4, &color, 4);
	}
}

void	add1(int key, t_frc *frc)
{
	if (key == 86)
		frc->key.fo = 1;
	if (key == 83)
		frc->key.f = 1;
	if (key == 84)
		frc->key.s = 1;
	if (key == 85)
		frc->key.t = 1;
	if (key == 46)
		frc->key.mouse_on = 1;
	if (key == 33)
		frc->key.six = 1;
	if (key == 30)
		frc->key.seven = 1;
	if (key == 18)
		frc->key.one = 1;
	if (key == 19)
		frc->key.two = 1;
	if (key == 20)
		frc->key.three = 1;
	if (key == 21)
		frc->key.four = 1;
	if (key == 23)
		frc->key.five = 1;
}

void	add2(int key, t_frc *frc)
{
	if (key == 86)
		frc->key.fo = 0;
	if (key == 83)
		frc->key.f = 0;
	if (key == 84)
		frc->key.s = 0;
	if (key == 85)
		frc->key.t = 0;
	if (key == 46)
		frc->key.mouse_on = 0;
	if (key == 33)
		frc->key.six = 0;
	if (key == 30)
		frc->key.seven = 0;
	if (key == 18)
		frc->key.one = 0;
	if (key == 19)
		frc->key.two = 0;
	if (key == 20)
		frc->key.three = 0;
	if (key == 21)
		frc->key.four = 0;
	if (key == 23)
		frc->key.five = 0;
}

void	add3(t_frc *frc)
{
	if (frc->key.six == 1)
		frc->color -= 4;
	if (frc->key.seven == 1 && frc->color > 4)
		frc->color += 4;
	if (frc->key.one == 1)
		frc->name == 4 ? (frc->color = 5636) :\
		(frc->color = 1792);
	if (frc->key.two == 1)
		frc->color = 16710132;
	if (frc->key.three == 1)
		frc->color = 14711680;
	if (frc->key.four == 1)
		frc->color = 11911616;
	if (frc->key.five == 1)
		frc->name == 4 ? (frc->color = 3300) :\
		(frc->color = 1548);
}

int		x_close(void)
{
	exit(0);
	return (0);
}
