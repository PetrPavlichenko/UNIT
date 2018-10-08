/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 18:43:05 by ppavlich          #+#    #+#             */
/*   Updated: 2017/06/30 18:43:09 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	mlx_win_init(t_w *w)
{
	w->mlx = mlx_init();
	w->win = mlx_new_window(w->mlx, WIN_X, WIN_Y, "WOLF");
	w->img = mlx_new_image(w->mlx, WIN_X, WIN_Y);
	w->img_ptr = mlx_get_data_addr(w->img,
		&w->bpp, &w->sl, &w->endian);
}

int		main(void)
{
	t_w	w;

	mlx_win_init(&w);
	//init(&w);
	//ft_reading(&w, "src/map");
	//ft_raycast(&w);
	mlx_loop_hook(w.mlx, ft_kek, &w);
	mlx_loop(w.mlx);
	free((void *)w.tex);
	return (0);
}
