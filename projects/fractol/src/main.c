/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 22:54:31 by ppavlich          #+#    #+#             */
/*   Updated: 2017/04/04 19:07:34 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_init(t_frc *frc)
{
	add_init(frc);
	frc->jx = 0.28;
	frc->jy = 0.05;
	frc->key.up = 0;
	frc->key.down = 0;
	frc->key.left = 0;
	frc->key.right = 0;
	frc->key.i_p = 0;
	frc->key.i_m = 0;
	frc->key.one = 0;
	frc->key.two = 0;
	frc->key.three = 0;
	frc->key.four = 0;
	frc->key.five = 0;
	frc->key.six = 0;
	frc->key.seven = 0;
	frc->key.f = 0;
	frc->key.s = 0;
	frc->key.t = 0;
	frc->key.fo = 0;
	frc->key.fi = 0;
}

void		run_fract(t_frc *frc)
{
	if (frc->name == 1)
		julia(frc);
	if (frc->name == 2)
		mandelbrot(frc);
	if (frc->name == 3)
		burningship(frc);
	if (frc->name == 4)
		biomorph(frc);
	if (frc->name == 5)
		spider(frc);
}

int			check_name(char *str)
{
	if (!ft_strcmp("julia", str) || str[0] == '1')
		return (1);
	if (!ft_strcmp("mandelbrot", str) || str[0] == '2')
		return (2);
	if (!ft_strcmp("burningship", str) || str[0] == '3')
		return (3);
	if (!ft_strcmp("biomorph", str) || str[0] == '4')
		return (4);
	if (!ft_strcmp("spider", str) || str[0] == '5')
		return (5);
	return (0);
}

void		mlx_win_init(t_frc *frc)
{
	frc->mlx = mlx_init();
	frc->win = mlx_new_window(frc->mlx, WIN_X, WIN_Y, "Fract'ol");
	frc->img = mlx_new_image(frc->mlx, WIN_X, WIN_Y);
	frc->img_ptr = mlx_get_data_addr(frc->img,
		&frc->bpp, &frc->sl, &frc->endian);
}

int			main(int argc, char **argv)
{
	t_frc		frc;

	if (argc == 2)
	{
		if ((frc.name = check_name(argv[1])) == 0)
			name_error();
		mlx_win_init(&frc);
		ft_init(&frc);
		run_fract(&frc);
		mlx_loop_hook(frc.mlx, ft_kek, &frc);
		mlx_loop(frc.mlx);
	}
	else
		arg_error();
}
