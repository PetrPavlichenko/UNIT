/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 16:48:15 by ppavlich          #+#    #+#             */
/*   Updated: 2017/09/26 16:48:20 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_ls	ls;
	t_lst	*t;
	char	**arr;

	ls.flag = (t_flag *)malloc(1024);
	ft_init(&ls);
	if (argc >= 2)
	{
		check_dir_and_file(argv) ? ft_check_inp(&ls, argv) \
		: ft_check_inp(&ls, rewrite_inp(argv));
		ft_del_lst(&ls.start);
	}
	if (argc == 1)
	{
		arr = alloc_2d_arr(1, 2);
		arr[1][0] = '.';
		ft_check_inp(&ls, arr);
		ft_del_lst(&ls.start);
	}
	t = ls.start;
	return (0);
}
