/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 18:13:05 by ppavlich          #+#    #+#             */
/*   Updated: 2017/09/26 18:13:09 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_check(t_ls *ls, char **inp, int i)
{
	int	j;

	j = 1;
	if (inp[i][j] == '\0')
		ft_error_dir("-");
	while (inp[i][j])
	{
		(inp[i][j] == 'R') ? ls->flag->rb = 1 : 0;
		(inp[i][j] == 'r') ? ls->flag->r = 1 : 0;
		(inp[i][j] == 'a') ? ls->flag->a = 1 : 0;
		(inp[i][j] == 't') ? ls->flag->t = 1 : 0;
		(inp[i][j] == 'l') ? ls->flag->l = 1 : 0;
		(inp[i][j] == 's') ? ls->flag->s = 1 : 0;
		(inp[i][j] == 'i') ? ls->flag->i = 1 : 0;
		if (!(inp[i][j] == 'R' || inp[i][j] == 'r' || inp[i][j] == 'a' || \
			inp[i][j] == 't' || inp[i][j] == 'l' || inp[i][j] == 's' || \
			inp[i][j] == 'i'))
		{
			ft_error_flag(inp[i][j]);
			exit(-1);
		}
		j++;
	}
	return (1);
}

void	ft_norm2(t_ls *ls, char *path, t_lst *t)
{
	t_lst			*tmp;

	tmp = t;
	(ls->flag->l == 1 || ls->flag->s == 1) ? print4((int)count_total(tmp)) : 0;
	while (tmp)
	{
		if (tmp->type_f == 'g')
			ft_error_dir(tmp->name);
		else
			ls->flag->l == 1 ? print_info(tmp, \
				ft_strjoin(path, tmp->name), ls) : print1(tmp->name, ls, tmp);
		tmp = tmp->next;
	}
	tmp = t;
	if (ls->flag->rb == 1)
		while (tmp)
		{
			if (tmp->type_f == 'd' && !(ft_strcmp(tmp->name, ".") == 0 \
				|| ft_strcmp(tmp->name, "..") == 0))
			{
				print2(ft_strjoin(path, tmp->name));
				ft_dir_open(ls, ft_strjoin(path, tmp->name));
			}
			tmp = tmp->next;
		}
}

void	ft_dir_open(t_ls *ls, char *str)
{
	DIR				*dir;
	struct dirent	*entry;
	t_lst			*t;
	char			*path;

	t = 0;
	dir = opendir(str);
	path = ft_strjoin(str, "/");
	if (!dir)
	{
		print3(path);
		ft_putendl_fd(strerror(errno), 2);
	}
	while ((entry = readdir(dir)) != NULL)
	{
		if (ls->flag->a == 0 && entry->d_name[0] == '.')
			;
		else
			ft_chk_type_d(entry->d_name, \
				ft_strjoin(path, entry->d_name), &t);
	}
	closedir(dir);
	ft_sort(ls, &t, 2);
	ft_norm2(ls, path, t);
	ft_del_lst(&t);
}

void	ft_norm1(t_ls *ls, char **inp, int i)
{
	t_lst		*t;

	t = ls->start;
	while (t)
	{
		(t->type_f == 'g') ? ft_error_dir(t->name) : 0;
		if (t->type_f == 'd')
		{
			if (ls->first == 0)
				(0 == ft_strcmp(inp[i], ".")) ? 0 : print3(t->name);
			else
				print2(t->name);
			ft_dir_open(ls, t->name);
		}
		else
		{
			if (ls->flag->l == 1 && t->type_f != 'g')
				print_info(t, t->name, ls);
			else if (t->type_f != 'g')
				print1(t->name, ls, t);
		}
		ls->first = 1;
		t = t->next;
	}
}

void	ft_check_inp(t_ls *ls, char **inp)
{
	int i;

	i = 1;
	while (inp[i])
		if (inp[i][0] == '-')
		{
			if (ft_check(ls, inp, i) > 0)
				i++;
		}
		else
			break ;
	ft_chk_type(ls, i, inp);
	ft_sort(ls, &(ls->start), 1);
	ft_norm1(ls, inp, i);
}
