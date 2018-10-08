/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wollf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 15:51:15 by ppavlich          #+#    #+#             */
/*   Updated: 2017/06/30 15:51:24 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H

# define WOLF_H
# define WIN_X	800
# define WIN_Y	600
# define TEX_W	64
# define TEX_H	64
# define MAP_W	24
# define MAP_H	24

# include <math.h>
# include <string.h>
# include <fcntl.h>
# include <time.h>
# include <stdio.h>
# include "mlx.h"
# include "../libft/libft.h"

typedef struct	s_key
{
	int			esc;
	int			a;
	int			s;
	int			d;
	int			w;
}				t_key;

typedef	struct	s_all
{
	char		**map;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		time;
	double		oldtime;
	double		cam_x;
	double		raypos_x;
	double		raypos_y;
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		deltadist_x;
	double		deltadist_y;
	double		sidedist_x;
	double		sidedist_y;
	double		prepwalldist;
	double		step_x;
	double		step_y;
	int			hit;
	int			side;
	double		lineheight;
	double		drawstart;
	double		drawend;
	int			color;
	double		frametime;
	double		movespeed;
	double		rotspeed;
	double		olddir_x;
	double		oldplane_x;
	double		wall_x;
	int			tex_num;
	double		tex_x;
	double		tex_y;
	double		fps;
	int			y;
	int			d;
	double		f_xw;
	double		f_yw;
	double		distwall;
	double		dist_plr;
	double		ftex_x;
	double		ftex_y;
	char		*str;
}				t_all;

typedef	struct	s_tex
{
	void		*img;
	char		*path;
}				t_tex;

typedef	struct	s_w
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_ptr;
	int			bpp;
	int			sl;
	int			endian;
	int			fd;
	t_key		key;
	t_all		all;
	t_tex		*tex;
}				t_w;

void			ft_print_str(t_w *w, char *str);
void			right(t_w *w);
void			left(t_w *w);
int				close_x(void);
int				ft_image_pixel_get(int x, int y, t_tex *img, t_w *w);
void			draw_tex(t_w *w, int x, int ds, int de);
void			put_pix_to_img(t_w *w, int x, int y, int color);
int				ft_kek(t_w *w);
void			ft_reading(t_w	*w, char *file);
void			ft_raycast(t_w *w);
void			init(t_w *w);
void			draw_floors(t_w *w, int x);

#endif
