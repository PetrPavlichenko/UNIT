/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:00:07 by ppavlich          #+#    #+#             */
/*   Updated: 2017/11/26 14:08:10 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H

# define FT_SELECT_H

# include <termios.h>
# include <stdlib.h>
# include <term.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <signal.h>
# include "../libft/libft.h"

typedef	struct		s_selct
{
	int				cur_file;
	int				count_files;
	char			*selected;
	char			*deleted;
}					t_selct;

typedef	struct		s_term
{
	struct termios	dafault_term;
	struct termios	сur_term;
	char			*name;
	int				width;
	int				high;
	int				max_len;
	int				small;
	int				cols;
	int				cur_col;
	int				is_print;
	char			*str;
	t_selct			*sel;
	char			***argv1;
}					t_term;

t_term				*g_term;

void				term_err(void);
t_selct				*set_input(char **arr);
int					count_lines(t_selct *sel, t_term *term);
void				set_keypress(t_term *term);
void				reset_keypress(t_term *term);
void				chk_keys(t_selct *sel, char **arr, int fd, t_term *term);
void				circle_inp(t_selct *sel, int f);
void				print_arr(t_selct *sel, char **arr, int fd, t_term *term);
void				clear_outp(t_selct *sel, int fd, t_term *term);
void				arg_err(void);
void				return_outp(t_selct *sel,\
					char **arr, int fd, t_term *term);
void				exit_func(t_selct *sel, int fd, t_term *term);
void				ft_delete(t_selct *sel);
void				chk_signal(t_term *term, char **argv);
void				chk_col(t_term *term, char **argv);
void				ft_clear(void);
void				alloc_term(int fd);
int					count_lines_for_c(t_selct *sel, t_term *term);

#endif
