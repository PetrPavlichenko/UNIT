/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 19:14:38 by ppavlich          #+#    #+#             */
/*   Updated: 2017/10/17 19:14:42 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_chk_type(t_ls *ls, int i, char **inp)
{
	struct stat buff;

	i -= 1;
	while (inp[++i])
	{
		if (lstat(inp[i], &buff) == 0)
			if (S_ISLNK(buff.st_mode))
			{
				ft_list_c(ls, 'l', inp[i], &buff);
				continue ;
			}
		if (stat(inp[i], &buff) == 0)
		{
			(S_ISDIR(buff.st_mode)) ? ft_list_c(ls, 'd', inp[i], &buff) : 0;
			(S_ISREG(buff.st_mode)) ? ft_list_c(ls, '-', inp[i], &buff) : 0;
			(S_ISCHR(buff.st_mode)) ? ft_list_c(ls, 'c', inp[i], &buff) : 0;
			(S_ISBLK(buff.st_mode)) ? ft_list_c(ls, 'b', inp[i], &buff) : 0;
			(S_ISSOCK(buff.st_mode)) ? \
			ft_list_c(ls, 's', inp[i], &buff) : 0;
		}
		else
			ft_error_dir(inp[i]);
	}
}

void	ft_chk_type_d(char *name, char *path, t_lst **lst)
{
	struct stat buff;

	if (lstat(path, &buff) == 0)
	{
		if (S_ISLNK(buff.st_mode))
		{
			ft_list_c_d(lst, 'l', name, &buff);
		}
		else if (stat(path, &buff) == 0)
		{
			(S_ISDIR(buff.st_mode)) ? ft_list_c_d(lst, 'd', name, &buff) : 0;
			(S_ISREG(buff.st_mode)) ? ft_list_c_d(lst, '-', name, &buff) : 0;
			(S_ISCHR(buff.st_mode)) ? ft_list_c_d(lst, 'c', name, &buff) : 0;
			(S_ISBLK(buff.st_mode)) ? ft_list_c_d(lst, 'b', name, &buff) : 0;
			if (S_ISSOCK(buff.st_mode))
				ft_list_c_d(lst, 's', name, &buff);
		}
		else
			ft_list_c_d(lst, 'g', name, &buff);
	}
}

void	set_permish(struct stat	*file_stat, t_lst *obj_f)
{
	int i;

	obj_f->permshn = ft_strnew(10);
	i = 0;
	(file_stat->st_mode & S_IRUSR) ? ((obj_f->permshn)[i++] = 'r')
		: ((obj_f->permshn)[i++] = '-');
	(file_stat->st_mode & S_IWUSR) ? ((obj_f->permshn)[i++] = 'w')
		: ((obj_f->permshn)[i++] = '-');
	(file_stat->st_mode & S_IXUSR) ? ((obj_f->permshn)[i++] = 'x')
		: ((obj_f->permshn)[i++] = '-');
	(file_stat->st_mode & S_IRGRP) ? ((obj_f->permshn)[i++] = 'r')
		: ((obj_f->permshn)[i++] = '-');
	(file_stat->st_mode & S_IWGRP) ? ((obj_f->permshn)[i++] = 'w')
		: ((obj_f->permshn)[i++] = '-');
	(file_stat->st_mode & S_IXGRP) ? ((obj_f->permshn)[i++] = 'x')
		: ((obj_f->permshn)[i++] = '-');
	(file_stat->st_mode & S_IROTH) ? ((obj_f->permshn)[i++] = 'r')
		: ((obj_f->permshn)[i++] = '-');
	(file_stat->st_mode & S_IWOTH) ? ((obj_f->permshn)[i++] = 'w')
		: ((obj_f->permshn)[i++] = '-');
	(file_stat->st_mode & S_IXOTH) ? ((obj_f->permshn)[i++] = 'x')
		: ((obj_f->permshn)[i++] = '-');
	(file_stat->st_mode & S_ISUID) ? ((obj_f->permshn)[2] = 's') : 0;
	(file_stat->st_mode & S_ISGID) ? ((obj_f->permshn)[5] = 's') : 0;
	(file_stat->st_mode & S_ISVTX) ? ((obj_f->permshn)[8] = 't') : 0;
}

void	print_info(t_lst *lst, char *path, t_ls *ls)
{
	if (ls->flag->i == 1)
	{
		ft_putstr(lst->ino);
		write(1, " ", 1);
	}
	if (ls->flag->s == 1)
	{
		ft_putstr(lst->bl_c);
		write(1, " ", 1);
	}
	write(1, &lst->type_f, 1);
	ft_putstr(lst->permshn);
	write(1, "  ", 2);
	ft_putstr(lst->links);
	write(1, " ", 1);
	ft_putstr(lst->user);
	write(1, "  ", 2);
	ft_putstr(lst->group);
	write(1, "  ", 2);
	ft_putstr(lst->size);
	write(1, " ", 1);
	ft_putstr(lst->date);
	write(1, " ", 1);
	lst->type_f == 'l' ? print_link(lst, path) : ft_putstr(lst->name);
	write(1, "\n", 1);
}
