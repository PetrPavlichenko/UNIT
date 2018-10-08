/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zaloop_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 01:00:18 by ppavlich          #+#    #+#             */
/*   Updated: 2017/03/29 01:00:20 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		press(int key, t_fdf *fdf)
{
	ft_fuck_norm(key, fdf);
	if (key == 123)
		fdf->flag.righ_rot = 1;
	if (key == 124)
		fdf->flag.lef_rot = 1;
	if (key == 125)
		fdf->flag.up_rot = 1;
	if (key == 126)
		fdf->flag.down_rot = 1;
	if (key == 53)
		fdf->flag.esc = 1;
	if (key == 13)
		fdf->flag.forward = 1;
	if (key == 1)
		fdf->flag.back = 1;
	if (key == 0)
		fdf->flag.right = 1;
	if (key == 2)
		fdf->flag.left = 1;
	return (0);
}

int		release(int key, t_fdf *fdf)
{
	ft_fuck_norm2(key, fdf);
	if (key == 123)
		fdf->flag.righ_rot = 0;
	if (key == 124)
		fdf->flag.lef_rot = 0;
	if (key == 125)
		fdf->flag.up_rot = 0;
	if (key == 126)
		fdf->flag.down_rot = 0;
	if (key == 13)
		fdf->flag.forward = 0;
	if (key == 1)
		fdf->flag.back = 0;
	if (key == 0)
		fdf->flag.right = 0;
	if (key == 2)
		fdf->flag.left = 0;
	return (0);
}

void	ft_check_flag(t_fdf *fdf)
{
	ft_fuck_norm3(fdf);
	if (fdf->flag.righ_rot == 1)
		fdf->v += 2;
	if (fdf->flag.lef_rot == 1)
		fdf->v -= 2;
	if (fdf->flag.up_rot == 1)
		fdf->h += 2;
	if (fdf->flag.down_rot == 1)
		fdf->h -= 2;
	if (fdf->flag.esc == 1)
		exit(0);
	if (fdf->flag.forward == 1)
		fdf->y2 -= 5;
	if (fdf->flag.back == 1)
		fdf->y2 += 5;
	if (fdf->flag.left == 1)
		fdf->x2 += 5;
	if (fdf->flag.right == 1)
		fdf->x2 -= 5;
}

int		ft_key_gopa(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 1, press, fdf);
	mlx_hook(fdf->win, 3, 2, release, fdf);
	ft_check_flag(fdf);
	mlx_clear_window(fdf->mlx, fdf->win);
	ft_draw(fdf);
	ft_main_str(fdf);
	return (0);
}
