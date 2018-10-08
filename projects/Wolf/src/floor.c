/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 14:33:51 by ppavlich          #+#    #+#             */
/*   Updated: 2017/09/21 14:34:02 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	pixel_on_floor(t_w *w, int x, int y)
{
	w->all.color = ft_image_pixel_get(w->all.ftex_x, w->all.ftex_y,
		&w->tex[6], w);
	put_pix_to_img(w, x, y, w->all.color);
	w->all.color = ft_image_pixel_get(w->all.ftex_x, w->all.ftex_y,
		&w->tex[7], w);
	put_pix_to_img(w, x, WIN_Y - y, w->all.color);
}

void	draw_floor(t_w *w, int x)
{
	double	cur_dis;
	double	cur_fl_x;
	double	cur_fl_y;
	double	weght;
	int		y;

	if (w->all.drawend < WIN_Y)
		y = w->all.drawend;
	else
		return ;
	while (++y != WIN_Y)
	{
		cur_dis = WIN_Y / (2. * y - WIN_Y);
		weght = (cur_dis - w->all.dist_plr) / \
		(w->all.distwall - w->all.dist_plr);
		cur_fl_x = weght * w->all.f_xw + (1. - weght) * w->all.pos_x;
		cur_fl_y = weght * w->all.f_yw + (1. - weght) * w->all.pos_y;
		w->all.ftex_x = ((int)(cur_fl_x * TEX_W)) % TEX_W;
		w->all.ftex_y = ((int)(cur_fl_y * TEX_H)) % TEX_H;
		pixel_on_floor(w, x, y);
	}
}

void	draw_floors(t_w *w, int x)
{
	if (w->all.side == 0 && w->all.raydir_x > 0)
	{
		w->all.f_xw = w->all.map_x;
		w->all.f_yw = w->all.map_y + w->all.wall_x;
	}
	else if (w->all.side == 0 && w->all.raydir_x < 0)
	{
		w->all.f_xw = w->all.map_x + 1.;
		w->all.f_yw = w->all.map_y + w->all.wall_x;
	}
	else if (w->all.side == 1 && w->all.raydir_y > 0)
	{
		w->all.f_xw = w->all.map_x + w->all.wall_x;
		w->all.f_yw = w->all.map_y;
	}
	else
	{
		w->all.f_xw = w->all.map_x + w->all.wall_x;
		w->all.f_yw = w->all.map_y + 1.;
	}
	w->all.distwall = w->all.prepwalldist;
	w->all.dist_plr = 0;
	if (w->all.drawend < 0)
		w->all.drawend = WIN_Y;
	draw_floor(w, x);
}
