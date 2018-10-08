/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 18:19:00 by ppavlich          #+#    #+#             */
/*   Updated: 2017/08/21 18:19:07 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	load_tex(t_w *w)
{
	int x;
	int y;

	x = TEX_W;
	y = TEX_H;
	w->tex[1].img = mlx_xpm_file_to_image(w->mlx, w->tex[1].path, &x, &y);
	w->tex[2].img = mlx_xpm_file_to_image(w->mlx, w->tex[2].path, &x, &y);
	w->tex[3].img = mlx_xpm_file_to_image(w->mlx, w->tex[3].path, &x, &y);
	w->tex[4].img = mlx_xpm_file_to_image(w->mlx, w->tex[4].path, &x, &y);
	w->tex[5].img = mlx_xpm_file_to_image(w->mlx, w->tex[5].path, &x, &y);
	w->tex[6].img = mlx_xpm_file_to_image(w->mlx, w->tex[6].path, &x, &y);
	w->tex[7].img = mlx_xpm_file_to_image(w->mlx, w->tex[7].path, &x, &y);
	w->tex[8].img = mlx_xpm_file_to_image(w->mlx, w->tex[8].path, &x, &y);
	w->tex[9].img = mlx_xpm_file_to_image(w->mlx, w->tex[9].path, &x, &y);
}

void	init(t_w *w)
{
	w->tex = (t_tex *)malloc(sizeof(t_tex) * 9);
	w->tex[0].path = "tex/bluestone.xpm";
	w->tex[1].path = "tex/colorstone.xpm";
	w->tex[2].path = "tex/greystone.xpm";
	w->tex[3].path = "tex/redbrick.xpm";
	w->tex[4].path = "tex/purplestone.xpm";
	w->tex[5].path = "tex/eagle.xpm";
	w->tex[6].path = "tex/mossy.xpm";
	w->tex[7].path = "tex/wood.xpm";
	w->tex[8].path = "tex/pillar.xpm";
	load_tex(w);
	w->all.pos_x = 2;
	w->all.pos_y = 2;
	w->all.dir_x = -1;
	w->all.dir_y = 0;
	w->all.plane_x = 0;
	w->all.plane_y = 0.66;
	w->all.time = 0;
	w->all.oldtime = 0;
	w->all.hit = 0;
}

void	put_pix_to_img(t_w *w, int x, int y, int color)
{
	if (x > 0 && x < WIN_X && y > 0 && y < WIN_Y)
	{
		color = mlx_get_color_value(w->mlx, color);
		ft_memcpy(w->img_ptr + y * WIN_X * 4 + x * 4, &color, 4);
	}
}

int		ft_image_pixel_get(int x, int y, t_tex *img, t_w *w)
{
	int				bpp;
	int				sl;
	int				en;
	char			*image;
	unsigned int	tmp;

	tmp = 0;
	w->all.color = 0;
	image = mlx_get_data_addr(img->img, &bpp, &sl, &en);
	if (x >= 0 && x < 64 && y >= 0 && y < 64)
		ft_memcpy((void *)(&tmp), (void *)((image + y * 64 * (bpp / 8))
			+ x * (bpp / 8)), 4);
	return (tmp);
}
