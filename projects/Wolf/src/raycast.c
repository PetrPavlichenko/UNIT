/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 15:47:39 by ppavlich          #+#    #+#             */
/*   Updated: 2017/08/22 15:47:44 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	calc1(t_w *w, int x)
{
	w->all.cam_x = 2 * x / (double)WIN_X - 1;
	w->all.raypos_x = w->all.pos_x;
	w->all.raypos_y = w->all.pos_y;
	w->all.raydir_x = w->all.dir_x + w->all.plane_x * w->all.cam_x;
	w->all.raydir_y = w->all.dir_y + w->all.plane_y * w->all.cam_x;
	w->all.map_x = (int)w->all.raypos_x;
	w->all.map_y = (int)w->all.raypos_y;
	w->all.deltadist_x = sqrt(1 + (w->all.raydir_y * w->all.raydir_y) / \
	(w->all.raydir_x * w->all.raydir_x));
	w->all.deltadist_y = sqrt(1 + (w->all.raydir_x * w->all.raydir_x) / \
	(w->all.raydir_y * w->all.raydir_y));
}

void	calc2(t_w *w)
{
	if (w->all.raydir_x < 0)
	{
		w->all.step_x = -1;
		w->all.sidedist_x = (w->all.raypos_x - w->all.map_x)\
		* w->all.deltadist_x;
	}
	else
	{
		w->all.step_x = 1;
		w->all.sidedist_x = (w->all.map_x + 1.0 - w->all.raypos_x)\
		* w->all.deltadist_x;
	}
	if (w->all.raydir_y < 0)
	{
		w->all.step_y = -1;
		w->all.sidedist_y = (w->all.raypos_y - w->all.map_y)\
		* w->all.deltadist_y;
	}
	else
	{
		w->all.step_y = 1;
		w->all.sidedist_y = (w->all.map_y + 1.0 - w->all.raypos_y)\
		* w->all.deltadist_y;
	}
}

void	calc3(t_w *w)
{
	w->all.hit = 0;
	while (w->all.hit == 0)
	{
		if (w->all.sidedist_x < w->all.sidedist_y)
		{
			w->all.sidedist_x += w->all.deltadist_x;
			w->all.map_x += w->all.step_x;
			w->all.side = 0;
		}
		else
		{
			w->all.sidedist_y += w->all.deltadist_y;
			w->all.map_y += w->all.step_y;
			w->all.side = 1;
		}
		if (w->all.map[w->all.map_y][w->all.map_x] > '0')
			w->all.hit = 1;
	}
	if (w->all.side == 0)
		w->all.prepwalldist = (w->all.map_x - w->all.raypos_x + \
		(1 - w->all.step_x) / 2) / w->all.raydir_x;
	else
		w->all.prepwalldist = (w->all.map_y - w->all.raypos_y + \
		(1 - w->all.step_y) / 2) / w->all.raydir_y;
}

void	calc4(t_w *w)
{
	w->all.lineheight = (int)(WIN_Y / w->all.prepwalldist);
	w->all.drawstart = -w->all.lineheight / 2 + WIN_Y / 2;
	if (w->all.drawstart < 0)
		w->all.drawstart = 0;
	w->all.drawend = w->all.lineheight / 2 + WIN_Y / 2;
	if (w->all.drawend >= WIN_Y)
		w->all.drawend = WIN_Y - 1;
	w->all.tex_num = w->all.map[w->all.map_y][w->all.map_x] - 47;
	if (w->all.side == 0)
		w->all.wall_x = w->all.raypos_y + w->all.prepwalldist *\
		w->all.raydir_y;
	else
		w->all.wall_x = w->all.raypos_x + w->all.prepwalldist *\
		w->all.raydir_x;
	w->all.wall_x -= floor((w->all.wall_x));
	w->all.tex_x = (int)(w->all.wall_x * (double)TEX_W);
	if (w->all.side == 0 && w->all.raydir_x > 0)
		w->all.tex_x = TEX_W - w->all.tex_x - 1;
	if (w->all.side == 1 && w->all.raydir_y < 0)
		w->all.tex_x = TEX_W - w->all.tex_x - 1;
	w->all.y = w->all.drawstart;
}

void	ft_raycast(t_w *w)
{
	int		x;

	x = -1;
	while (++x < WIN_X)
	{
		calc1(w, x);
		calc2(w);
		calc3(w);
		calc4(w);
		draw_tex(w, x, w->all.drawstart, w->all.drawend);
		draw_floors(w, x);
	}
	w->all.oldtime = w->all.time;
	w->all.time = clock();
	w->all.frametime = (w->all.time - w->all.oldtime) / CLOCKS_PER_SEC;
	w->all.fps = 1.0 / w->all.frametime;
	w->all.movespeed = w->all.frametime * 5.0;
	w->all.rotspeed = w->all.frametime * 3.0;
}
