/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:19:26 by ppavlich          #+#    #+#             */
/*   Updated: 2017/03/28 17:19:39 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mem_error(void)
{
	write(1, "allocation memory error\n", 24);
	exit(0);
}

void	ft_arg_error(void)
{
	write(1, "arguments error\n", 16);
	exit(0);
}

void	ft_inv_map(void)
{
	write(1, "invalid map\n", 12);
	exit(1);
}

void	ft_open_error(void)
{
	write(1, "open file error\n", 16);
	exit(0);
}

void	ft_init(t_fdf *fdf)
{
	fdf->vint = 0;
	fdf->x2 = 600;
	fdf->y2 = 900;
	fdf->zoom = 4.0;
	fdf->f = 0;
	fdf->h = 60;
	fdf->v = 0;
	fdf->z = 0;
	fdf->z3 = 1;
	fdf->clr = 0;
	fdf->flag.left = 0;
	fdf->flag.right = 0;
	fdf->flag.forward = 0;
	fdf->flag.back = 0;
	fdf->flag.esc = 0;
	fdf->flag.lef_rot = 0;
	fdf->flag.righ_rot = 0;
	fdf->flag.up_rot = 0;
	fdf->flag.down_rot = 0;
	fdf->flag.zoom_min = 0;
	fdf->flag.zoom_plus = 0;
}
