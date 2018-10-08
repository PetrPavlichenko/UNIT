/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 22:48:24 by ppavlich          #+#    #+#             */
/*   Updated: 2017/04/04 19:12:04 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# define WIN_X	1000
# define WIN_Y	1000

# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef	struct	s_spd
{
	double	z1x;
	double	z1y;
	double	c1x;
	double	c1y;
	double	z2x;
	double	z2y;
	double	c2x;
	double	c2y;
}				t_spd;

typedef	struct	s_key
{
	int			esc;
	int			zoomp;
	int			zoomm;
	int			up;
	int			down;
	int			left;
	int			right;
	int			i_p;
	int			i_m;
	int			one;
	int			two;
	int			three;
	int			four;
	int			five;
	int			six;
	int			seven;
	int			mouse_on;
	int			f;
	int			s;
	int			t;
	int			fo;
	int			fi;
}				t_key;

typedef	struct	s_frc
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_ptr;
	int			color;
	double		zoom;
	int			endian;
	int			sl;
	int			bpp;
	int			name;
	int			iter;
	int			side;
	double		diff_x;
	double		diff_y;
	double		zx;
	double		zy;
	double		movex;
	double		movey;
	double		jx;
	double		jy;
	t_key		key;
}				t_frc;

void			ft_str_view(t_frc *frc);
void			add_init(t_frc *frc);
void			add3_2(t_frc *frc);
void			add3(t_frc *frc);
void			add2(int key, t_frc *frc);
void			add1(int key, t_frc *frc);
int				x_close(void);
void			run_fract(t_frc *frc);
void			put_pix_to_img(t_frc *frc, int x, int y, int color);
int				ft_kek(t_frc *frc);
int				mouse_move(int x, int y, t_frc *frc);
void			mandelbrot(t_frc *frc);
void			julia(t_frc *frc);
void			burningship(t_frc *frc);
void			biomorph(t_frc *frc);
void			spider(t_frc *frc);
void			name_error(void);
void			arg_error(void);
#endif
