/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:40:14 by ppavlich          #+#    #+#             */
/*   Updated: 2017/11/30 17:41:14 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_output(t_gnl *r, t_gnl **pr, char **line)
{
	int				rt;
	char			*tmp;

	if (r->fs <= 0)
	{
		rt = r->rs;
		free(r->read);
		free(r);
		*pr = NULL;
		return ((rt < 0) ? (-1) : (0));
	}
	tmp = ft_strncpy(ft_strnew(r->cp_len), r->read, r->cp_len);
	*line = tmp;
	r->fs = r->fs - r->cp_len - (*(r->endl) == '\n');
	ft_strncpy(r->read, (r->endl + 1), r->fs);
	r->endl = r->read;
	return (1);
}

static int			ft_detector(t_gnl *r)
{
	while (*(r->endl) != '\n' && (r->fs > r->endl - r->read))
		r->endl++;
	r->cp_len = r->endl - r->read;
	if (*(r->endl) == '\n')
		return (r->fs > r->cp_len);
	return (0);
}

static t_gnl		*ft_init_n_resizer(t_gnl *r)
{
	char			*tmp;

	if (!r)
	{
		if (!(r = (t_gnl *)malloc(sizeof(t_gnl))))
			return (NULL);
		if (!(r->read = ft_strnew(BUFF_SIZE)))
			return (NULL);
		r->endl = r->read;
		r->len = BUFF_SIZE;
		r->cp_len = 0;
		r->fs = 0;
		r->rs = 1;
		return (r);
	}
	if (!(tmp = ft_strcpy(ft_strnew(r->len * 2), r->read)))
		return (NULL);
	free(r->read);
	r->read = tmp;
	r->endl = r->read + r->cp_len;
	r->len = r->len * 2;
	return (r);
}

int					get_next_line(int const fd, char **line)
{
	static t_gnl	*r[1000];

	if (fd >= 1000 || fd < 0 || !line || read(fd, 0, 0) < 0)
		return (-1);
	if (!r[fd] && !(r[fd] = ft_init_n_resizer(r[fd])))
		return (-1);
	while (r[fd]->rs > 0 && !(ft_detector(r[fd])))
	{
		if (r[fd]->fs + BUFF_SIZE > r[fd]->len && !(ft_init_n_resizer(r[fd])))
			return (-1);
		r[fd]->rs = read(fd, r[fd]->read + r[fd]->fs, BUFF_SIZE);
		r[fd]->fs += r[fd]->rs;
	}
	return (ft_output(r[fd], &r[fd], line));
}
