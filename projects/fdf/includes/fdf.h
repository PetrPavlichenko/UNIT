/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 17:14:28 by ppavlich          #+#    #+#             */
/*   Updated: 2017/04/01 17:14:37 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# define WIN_X 1600
# define WIN_Y 1600
# define CEN_X WIN_X/2
# define CEN_Y WIN_Y/2

# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct	s_coord
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			signx;
	int			signy;
}				t_coord;

typedef struct	s_read
{
	int			x;
	int			y;
	int			z;
	double		x_n;
	double		y_n;
	int			color;
	int			max_y;
	int			len_x;
	int			red;
	int			green;
	int			blue;
}				t_read;

typedef	struct	s_flag
{
	int			esc;
	int			left;
	int			right;
	int			forward;
	int			back;
	int			lef_rot;
	int			righ_rot;
	int			up_rot;
	int			down_rot;
	int			zoom_min;
	int			zoom_plus;
	int			z_minus;
	int			z_plus;
	int			r1;
	int			g2;
	int			b3;
	int			k4;
}				t_flag;

typedef	struct	s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	int			fd;
	int			m_x;
	int			m_y;
	double		dist_x;
	double		dist_y;
	int			del_x;
	int			del_y;
	int			error;
	int			error2;
	int			f;
	double		zoom;
	int			h;
	int			v;
	int			z;
	int			x2;
	int			y2;
	double		z3;
	int			clr;
	int			vint;
	t_coord		crd;
	t_read		***map;
	t_flag		flag;
}				t_fdf;

void			ft_main_str(t_fdf *fdf);
int				ft_colr(t_fdf *fdf, int i, int j);
void			ft_fuck_norm3(t_fdf *fdf);
void			ft_fuck_norm2(int key, t_fdf *fdf);
void			ft_fuck_norm(int key, t_fdf *fdf);
int				ft_key_gopa(t_fdf *fdf);
int				press(int key, t_fdf *fdf);
int				release(int key, t_fdf *fdf);
void			ft_check_flag(t_fdf *fdf);
void			ft_mem_error(void);
void			ft_arg_error(void);
void			ft_inv_map(void);
void			ft_open_error(void);
void			ft_init(t_fdf *fdf);
void			ft_valid(t_fdf *fdf, char **arr);
int				ft_atoi_base(char *str, int base);
int				get_next_line(const int fd, char **line);
void			ft_draw(t_fdf *fdf);
void			ft_readd(char *file, t_fdf *fdf);

#endif
