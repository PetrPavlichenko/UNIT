/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zaloop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 19:17:47 by ppavlich          #+#    #+#             */
/*   Updated: 2017/08/21 19:17:53 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	jopa(t_w *w)
{
	int		i;
	int		j;

	i = 0;
	while (i < WIN_Y)
	{
		j = 0;
		while (j < WIN_X)
		{
			//dir = ft_2d_to_3d(j, i, k->cam);
			//if (sphere_intersect(k->cam->p, dir, &sph))
			//	put_pix_to_img(k, j, i, RED);
			put_pix_to_img(w, j, i, 65280);
			//write(1, "1", 1);
			j++;
		}
		//printf("i == %d, j max =%d\n", i, j);
		i++;
	}
}

void	ft_check_key(t_w *w)
{
	if (w->key.esc == 1)
		exit(0);
	if (w->key.w == 1)
	{
		if (w->all.map[(int)w->all.pos_y][(int)(w->all.pos_x\
		+ w->all.dir_x * w->all.movespeed)] <= '0')
			w->all.pos_x += w->all.dir_x * w->all.movespeed;
		if (w->all.map[(int)(w->all.pos_y + w->all.dir_y * \
		w->all.movespeed)][(int)w->all.pos_x] <= '0')
			w->all.pos_y += w->all.dir_y * w->all.movespeed;
	}
	if (w->key.s == 1)
	{
		if (w->all.map[(int)w->all.pos_y][(int)(w->all.pos_x - \
		w->all.dir_x * w->all.movespeed)] <= '0')
			w->all.pos_x -= w->all.dir_x * w->all.movespeed;
		if (w->all.map[(int)(w->all.pos_y - w->all.dir_y * \
			w->all.movespeed)][(int)w->all.pos_x] <= '0')
			w->all.pos_y -= w->all.dir_y * w->all.movespeed;
	}
	if (w->key.d == 1)
		right(w);
	if (w->key.a == 1)
		left(w);
}

int		ft_press(int key, t_w *w)
{
	if (key == 53)
		w->key.esc = 1;
	if (key == 0)
		w->key.a = 1;
	if (key == 1)
		w->key.s = 1;
	if (key == 2)
		w->key.d = 1;
	if (key == 13)
		w->key.w = 1;
	return (0);
}

int		ft_release(int key, t_w *w)
{
	if (key == 53)
		w->key.esc = 0;
	if (key == 0)
		w->key.a = 0;
	if (key == 1)
		w->key.s = 0;
	if (key == 2)
		w->key.d = 0;
	if (key == 13)
		w->key.w = 0;
	return (0);
}

int		ft_kek(t_w *w)
{
	mlx_hook(w->win, 2, 1, ft_press, w);
	mlx_hook(w->win, 3, 2, ft_release, w);
	mlx_hook(w->win, 17, 0L, close_x, w);
	ft_check_key(w);
	mlx_destroy_image(w->mlx, w->img);
	w->img = mlx_new_image(w->mlx, WIN_X, WIN_Y);
	//ft_raycast(w);
	jopa(w);
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	w->all.str = "fps = ";
	mlx_string_put(w->mlx, w->win, 20, 10, 0xFFffff, w->all.str);
	w->all.str = ft_itoa(w->all.fps);
	mlx_string_put(w->mlx, w->win, 90, 10, 0xFFffff, w->all.str);
	free(w->all.str);
	return (0);
}
