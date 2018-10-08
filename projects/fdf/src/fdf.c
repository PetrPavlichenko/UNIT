/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:19:52 by ppavlich          #+#    #+#             */
/*   Updated: 2017/03/28 17:19:55 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc == 2)
	{
		fdf.mlx = mlx_init();
		fdf.win = mlx_new_window(fdf.mlx, WIN_X, WIN_Y, "fdf");
		fdf.img = mlx_new_image(fdf.mlx, WIN_X, WIN_Y);
		ft_init(&fdf);
		ft_readd(argv[1], &fdf);
		fdf.dist_x = WIN_X / (fdf.m_x + 1);
		fdf.dist_y = WIN_Y / (fdf.m_y + 1);
		ft_draw(&fdf);
		ft_main_str(&fdf);
		mlx_loop_hook(fdf.mlx, ft_key_gopa, &fdf);
		mlx_loop(fdf.mlx);
	}
	else
		ft_arg_error();
	return (0);
}
