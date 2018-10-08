/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 20:23:51 by ppavlich          #+#    #+#             */
/*   Updated: 2017/10/09 20:23:55 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_list_c(t_ls *ls, char c, char *name_s, struct stat *buff)
{
	t_lst	*tmp;

	if (ls->start == 0)
	{
		ls->start = (t_lst *)malloc(sizeof(t_lst));
		ft_record(&ls->start, c, name_s, buff);
		ls->start->next = NULL;
	}
	else
	{
		tmp = (t_lst *)malloc(sizeof(t_lst));
		ft_record(&tmp, c, name_s, buff);
		tmp->next = ls->start;
		ls->start = tmp;
	}
}

void	ft_list_c_d(t_lst **lst, char c, char *name_s, struct stat *buff)
{
	t_lst	*tmp;

	tmp = *lst;
	if (tmp == 0)
	{
		tmp = (t_lst *)malloc(sizeof(t_lst));
		ft_record(&tmp, c, name_s, buff);
		tmp->next = NULL;
		*lst = tmp;
	}
	else
	{
		tmp = (t_lst *)malloc(sizeof(t_lst));
		ft_record(&tmp, c, name_s, buff);
		tmp->next = *lst;
		*lst = tmp;
	}
}

void	ft_record(t_lst **lst, char c, char *name_s, struct stat *buff)
{
	t_lst	*tmp;

	tmp = *lst;
	tmp->name = ft_strdup(name_s);
	tmp->type_f = c;
	set_permish(buff, tmp);
	tmp->links = ft_itoa_base(buff->st_nlink, 10);
	if (tmp->type_f == 'c' || tmp->type_f == 'b')
	{
		tmp->maj = ft_itoa_base(major(buff->st_rdev), 10);
		tmp->min = ft_itoa_base(minor(buff->st_rdev), 10);
	}
	else
		tmp->size = ft_itoa_base(buff->st_size, 10);
	tmp->user = ft_strdup((getpwuid(buff->st_uid))->pw_name);
	tmp->group = ft_strdup((getgrgid(buff->st_gid))->gr_name);
	tmp->bl_s = buff->st_blocks;
	tmp->bl_c = ft_strdup(ft_itoa_base(tmp->bl_s, 10));
	tmp->date = ft_strdup(ctime(&(buff->st_mtime)));
	tmp->s_date = (buff->st_mtimespec).tv_sec;
	tmp->s_ns = (buff->st_mtimespec).tv_nsec;
	(cmp_date(buff)) ? set_date(tmp, 1) : set_date(tmp, 0);
	tmp->ino = ft_itoa_base(buff->st_ino, 10);
}

int		cmp_date(struct stat *buff)
{
	time_t curtime;

	time(&curtime);
	if (((curtime / 2620800) - \
		((buff->st_mtimespec).tv_sec) / 2620800) >= 6)
		return (1);
	if ((curtime) < (buff->st_mtimespec).tv_sec)
		return (1);
	return (0);
}

void	set_date(t_lst *lst, int f)
{
	char	*t;
	int		i;
	int		j;

	i = 3;
	j = 0;
	t = ft_strnew(16);
	if (f == 1)
	{
		while (++i <= 9)
			t[j++] = (lst->date)[i];
		i = 18;
		t[j++] = ' ';
		while (++i <= 23)
			t[j++] = (lst->date)[i];
	}
	else
	{
		while (++i <= 15)
			t[j++] = (lst->date)[i];
	}
	free(lst->date);
	lst->date = t;
}
