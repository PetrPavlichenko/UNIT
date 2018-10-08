/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:20:36 by ppavlich          #+#    #+#             */
/*   Updated: 2017/03/28 17:20:39 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_len(char **all)
{
	int	i;

	i = 0;
	while (all[i] != NULL)
		i++;
	return (i);
}

void	ft_valid(t_fdf *fdf, char **arr)
{
	int k;

	k = ft_len(arr);
	if (fdf->f == 0)
	{
		fdf->m_x = k;
		fdf->f++;
	}
	else
	{
		if (k > fdf->m_x)
			arr[fdf->m_x] = NULL;
		if (k < fdf->m_x)
			ft_inv_map();
	}
}

void	ft_color_record(t_fdf *fdf, int x, int y, char **p)
{
	fdf->map[y][x]->color = ft_atoi_base(*p + 3, 16);
	fdf->map[y][x]->red = (fdf->map[y][x]->color >> 16);
	fdf->map[y][x]->green = (fdf->map[y][x]->color >> 8) \
	- (fdf->map[y][x]->color << 8);
	fdf->map[y][x]->blue = fdf->map[y][x]->color \
	- (fdf->map[y][x]->color << 16) - (fdf->map[y][x]->color << 8);
}

void	ft_struct_record(char **arr, t_fdf *fdf, int y)
{
	int		x;
	char	*p;

	x = -1;
	ft_valid(fdf, arr);
	if ((fdf->map[y] = (t_read **)malloc(sizeof(t_read *)\
		* (fdf->m_x + 1))) == NULL)
		ft_mem_error();
	while (arr[++x] != NULL)
	{
		fdf->map[y][x] = (t_read *)malloc(sizeof(t_read));
		if ((p = ft_strchr(arr[x], ',')))
			ft_color_record(fdf, x, y, &p);
		else
		{
			fdf->map[y][x]->color = 16777215;
			fdf->map[y][x]->red = 16724787;
			fdf->map[y][x]->green = 65280;
			fdf->map[y][x]->blue = 39423;
		}
		fdf->map[y][x]->x = x;
		fdf->map[y][x]->y = y;
		fdf->map[y][x]->z = -ft_atoi(arr[x]);
	}
}

void	ft_readd(char *file, t_fdf *fdf)
{
	char	*line;
	char	**arr;
	int		i;

	if ((fdf->fd = open(file, O_RDONLY)) == (-1))
		ft_open_error();
	i = 0;
	while (get_next_line(fdf->fd, &line) > 0)
		i++;
	if ((fdf->map = (t_read ***)malloc(sizeof(t_read **) * (i + 1))) == NULL)
		ft_mem_error();
	fdf->m_y = i;
	close(fdf->fd);
	if ((fdf->fd = open(file, O_RDONLY)) == (-1))
		ft_open_error();
	i = 0;
	while (get_next_line(fdf->fd, &line) != 0)
	{
		arr = ft_strsplit(line, ' ');
		ft_struct_record(arr, fdf, i);
		i++;
	}
}
