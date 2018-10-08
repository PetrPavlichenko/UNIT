/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:52:29 by ppavlich          #+#    #+#             */
/*   Updated: 2017/03/23 19:32:38 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_checkstr(char **str, char **line)
{
	char	*p;
	char	*tmp;

	if (*str != NULL)
	{
		if ((p = ft_strchr(*str, '\n')) != NULL)
		{
			*p = '\0';
			*line = ft_strdup(*str);
			tmp = ft_strdup(p + 1);
			free(*str);
			*str = tmp;
			return (1);
		}
	}
	return (0);
}

static int		ft_supp(int f, char **buff, char **str, char **line)
{
	char	*p;
	char	*tmp;

	if (*str == NULL)
		*str = ft_strdup("");
	if (f == 1)
		if ((p = ft_strchr(*buff, '\n')) != NULL)
		{
			*p = '\0';
			*line = ft_strdup(ft_strjoin(*str, *buff));
			free(*str);
			*str = ft_strdup(p + 1);
			ft_strdel(buff);
			return (1);
		}
	if (f == 2)
	{
		tmp = ft_strdup(*str);
		free(*str);
		*str = ft_strjoin(tmp, *buff);
		free(tmp);
	}
	return (0);
}

int				ft_read(int fd, char **line, char **buff, char **str)
{
	int		rs;
	int		f;

	f = 0;
	while ((rs = read(fd, *buff, BUFF_SIZE)) > 0)
	{
		(*buff)[rs] = '\0';
		if (ft_supp(1, buff, str, line))
		{
			f++;
			return (1);
		}
		else if (ft_supp(2, buff, str, line))
			;
	}
	if (rs == 0 && f == 0 && *str != NULL && ft_strlen(*str) != 0)
	{
		*line = ft_strdup(*str);
		free(*str);
		*str = NULL;
		return (1);
	}
	return (rs);
}

int				get_next_line(const int fd, char **line)
{
	char		*buff;
	static char	*str;
	int			res;

	if (BUFF_SIZE < 1 || fd < 0 || !line)
		return (-1);
	if ((buff = ft_strnew(BUFF_SIZE + 1)) == NULL)
		return (0);
	if (ft_checkstr(&str, line))
		return (1);
	res = ft_read(fd, line, &buff, &str);
	if (res == 0)
	{
		ft_strdel(&str);
	}
	ft_strdel(&buff);
	return (res);
}
