/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:04:31 by ppavlich          #+#    #+#             */
/*   Updated: 2017/01/11 14:04:37 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_dop(char **line, char **str, char **buff)
{
	char	*f;
	char	*tmp;

	if ((f = ft_strchr(*buff, '\n')))
	{
		*f = '\0';
		*line = ft_strjoin(*str, *buff);
		tmp = ft_strdup(f + 1);
		free(*str);
		*str = tmp;
		f = NULL;
		free(*buff);
		return (1);
	}
	return (0);
}

int			check_str(char **str, char **line)
{
	char *p;
	char *tmp;

	if (*str == NULL)
		return (0);
	if ((p = ft_strchr(*str, '\n')))
	{
		*p = 0;
		*line = ft_strdup(*str);
		tmp = ft_strdup(p + 1);
		free(*str);
		*str = tmp;
		p = NULL;
		return (1);
	}
	return (0);
}

int			ft_reading(const int fd, char **line, char **buff, char **str)
{
	int		rsize;
	char	*tmp;

	while ((rsize = read(fd, *buff, BUFF_SIZE)) > 0)
	{
		if (*str == NULL)
			*str = ft_strdup("");
		(*buff)[rsize] = '\0';
		if (ft_dop(line, str, buff))
			return (1);
		tmp = ft_strdup(*str);
		free(*str);
		*str = ft_strjoin(tmp, *buff);
		free(tmp);
	}
	if (rsize == 0 && (*str == NULL || (*str)[0] == 0))
		return (0);
	if (rsize < 0)
		return (-1);
	return (2);
}

t_gnl_str	*mult_fd(int fd, t_gnl_str **lst)
{
	t_gnl_str	*tmp;
	t_gnl_str	*new;

	if (*lst == NULL)
	{
		*lst = (t_gnl_str*)malloc(sizeof(t_gnl_str));
		(*lst)->fd_s = fd;
		(*lst)->str = NULL;
		(*lst)->next = NULL;
	}
	tmp = (*lst);
	while (tmp)
	{
		if (tmp->fd_s == fd)
			return (tmp);
		tmp = tmp->next;
	}
	new = (t_gnl_str *)malloc(sizeof(t_gnl_str));
	new->fd_s = fd;
	new->str = NULL;
	new->next = *lst;
	*lst = new;
	return (new);
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl_str	*lst = NULL;
	t_gnl_str			*ptr;
	char				*buff;
	int					res;

	if (fd < 0)
		return (-1);
	ptr = mult_fd(fd, &lst);
	if (check_str(&(ptr->str), line))
		return (1);
	if ((buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))) == NULL)
		return (-1);
	res = ft_reading(fd, line, &buff, &(ptr->str));
	if (res == 1)
		return (1);
	if (res == -1)
		return (-1);
	free(buff);
	buff = NULL;
	if (ptr->str == NULL || res == 0)
		return (0);
	*line = ft_strdup(ptr->str);
	free(ptr->str);
	ptr->str = NULL;
	return (1);
}
