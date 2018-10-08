/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 17:50:00 by ppavlich          #+#    #+#             */
/*   Updated: 2017/09/08 17:50:02 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_tex(t_w *w, int x, int ds, int de)
{
	int	d;

	d = 0;
	while (ds <= de)
	{
		d = (ds * 2) - (WIN_Y) + (w->all.lineheight);
		w->all.tex_y = ((d * TEX_H) / w->all.lineheight) / 2;
		w->all.color = ft_image_pixel_get(w->all.tex_x, w->all.tex_y, \
		&w->tex[w->all.tex_num], w);
		put_pix_to_img(w, x, ds, w->all.color);
		ds++;
	}
}

int		close_x(void)
{
	exit(0);
	return (0);
}

void	left(t_w *w)
{
	w->all.olddir_x = w->all.dir_x;
	w->all.dir_x = w->all.dir_x * cos(w->all.rotspeed) - \
	w->all.dir_y * sin(w->all.rotspeed);
	w->all.dir_y = w->all.olddir_x * sin(w->all.rotspeed) + \
	w->all.dir_y * cos(w->all.rotspeed);
	w->all.oldplane_x = w->all.plane_x;
	w->all.plane_x = w->all.plane_x * cos(w->all.rotspeed) - \
	w->all.plane_y * sin(w->all.rotspeed);
	w->all.plane_y = w->all.oldplane_x * sin(w->all.rotspeed) + \
	w->all.plane_y * cos(w->all.rotspeed);
}

void	right(t_w *w)
{
	w->all.olddir_x = w->all.dir_x;
	w->all.dir_x = w->all.dir_x * cos(-w->all.rotspeed) - \
	w->all.dir_y * sin(-w->all.rotspeed);
	w->all.dir_y = w->all.olddir_x * sin(-w->all.rotspeed) + \
	w->all.dir_y * cos(-w->all.rotspeed);
	w->all.oldplane_x = w->all.plane_x;
	w->all.plane_x = w->all.plane_x * cos(-w->all.rotspeed) - \
	w->all.plane_y * sin(-w->all.rotspeed);
	w->all.plane_y = w->all.oldplane_x * sin(-w->all.rotspeed) + \
	w->all.plane_y * cos(-w->all.rotspeed);
}
