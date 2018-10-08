/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zaloop_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 18:17:06 by ppavlich          #+#    #+#             */
/*   Updated: 2017/04/04 19:05:25 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mouse(int key, int x, int y, t_frc *frc)
{
	if (key == 5)
	{
		frc->zoom *= 1.1;
		frc->diff_x = (x - (WIN_X / 2)) * (frc->side / (WIN_X * frc->zoom));
		frc->diff_y = (y - (WIN_Y / 2)) * (frc->side / (WIN_Y * frc->zoom));
		frc->zx += frc->diff_x - ((x - (WIN_X / 2)) * \
			(frc->side / WIN_X) / frc->zoom);
		frc->zy += frc->diff_y - ((x - (WIN_Y / 2)) * \
			(frc->side / WIN_Y) / frc->zoom);
	}
	if (key == 4 && frc->zoom > 0.5)
	{
		frc->zoom /= 1.1;
		frc->diff_x = (x - (WIN_X / 2)) * (frc->side / (WIN_X * frc->zoom));
		frc->diff_y = (y - (WIN_Y / 2)) * (frc->side / (WIN_Y * frc->zoom));
		frc->zx += frc->diff_x - ((x - (WIN_X / 2)) * \
			(frc->side / WIN_X) / frc->zoom);
		frc->zy += frc->diff_y - ((x - (WIN_Y / 2)) * \
			(frc->side / WIN_Y) / frc->zoom);
	}
	return (0);
}

void	ft_check_key(t_frc *frc)
{
	add3(frc);
	add3_2(frc);
	if (frc->key.i_p == 1)
		frc->iter += 1;
	if (frc->key.i_m == 1 && frc->iter > 4)
		frc->iter -= 1;
	if (frc->key.up == 1)
		frc->movey -= 0.4 / frc->zoom;
	if (frc->key.down == 1)
		frc->movey += 0.4 / frc->zoom;
	if (frc->key.left == 1)
		frc->movex -= 0.4 / frc->zoom;
	if (frc->key.right == 1)
		frc->movex += 0.4 / frc->zoom;
	if (frc->key.zoomp == 1)
		frc->zoom *= 1.1;
	if (frc->key.zoomm == 1 && frc->zoom > 0.1)
		frc->zoom /= 1.1;
	if (frc->key.esc == 1)
		exit(0);
}

int		ft_press(int key, t_frc *frc)
{
	add1(key, frc);
	if (key == 87)
		frc->key.fi = 1;
	if (key == 53)
		frc->key.esc = 1;
	if (key == 24)
		frc->key.zoomp = 1;
	if (key == 27)
		frc->key.zoomm = 1;
	if (key == 13)
		frc->key.up = 1;
	if (key == 1)
		frc->key.down = 1;
	if (key == 0)
		frc->key.left = 1;
	if (key == 2)
		frc->key.right = 1;
	if (key == 29)
		frc->key.i_p = 1;
	if (key == 25)
		frc->key.i_m = 1;
	return (0);
}

int		ft_release(int key, t_frc *frc)
{
	add2(key, frc);
	if (key == 87)
		frc->key.fi = 0;
	if (key == 24)
		frc->key.zoomp = 0;
	if (key == 27)
		frc->key.zoomm = 0;
	if (key == 13)
		frc->key.up = 0;
	if (key == 1)
		frc->key.down = 0;
	if (key == 0)
		frc->key.left = 0;
	if (key == 2)
		frc->key.right = 0;
	if (key == 29)
		frc->key.i_p = 0;
	if (key == 25)
		frc->key.i_m = 0;
	return (0);
}

int		ft_kek(t_frc *frc)
{
	mlx_hook(frc->win, 2, 1, ft_press, frc);
	mlx_hook(frc->win, 3, 2, ft_release, frc);
	mlx_hook(frc->win, 17, 0L, x_close, frc);
	if (frc->name == 1)
		mlx_hook(frc->win, 6, 0, mouse_move, frc);
	mlx_mouse_hook(frc->win, ft_mouse, frc);
	ft_check_key(frc);
	mlx_destroy_image(frc->mlx, frc->img);
	frc->img = mlx_new_image(frc->mlx, WIN_X, WIN_Y);
	run_fract(frc);
	mlx_put_image_to_window(frc->mlx, frc->win, frc->img, 0, 0);
	ft_str_view(frc);
	return (0);
}
