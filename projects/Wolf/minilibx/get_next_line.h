/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:12:50 by ppavlich          #+#    #+#             */
/*   Updated: 2017/01/11 14:12:53 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 1024

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "../libft/libft.h"

typedef	struct			s_gnl_str
{
	int					fd_s;
	char				*str;
	struct s_gnl_str	*next;
}						t_gnl_str;

int						get_next_line(const int fd, char **line);
int						ft_reading(const int fd, char **line,\
	char **buff, char **str);
int						check_str(char **str, char **line);
t_gnl_str				*mult_fd(int fd, t_gnl_str **lst);
int						ft_dop(char **line, char **str, char **buff);

#endif
