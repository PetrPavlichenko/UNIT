/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 16:50:14 by ppavlich          #+#    #+#             */
/*   Updated: 2017/09/26 16:50:17 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# include <dirent.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include "../libft/libft.h"

typedef struct		s_flag
{
	int				l;
	int				rb;
	int				r;
	int				a;
	int				t;
	int				s;
	int				i;
}					t_flag;

typedef	struct		s_out
{
	char			*outp;
	struct s_out	*next;
}					t_out;

typedef	struct		s_lst
{
	char			type_f;
	char			*permshn;
	char			*links;
	char			*user;
	char			*group;
	char			*size;
	char			*date;
	char			*name;
	char			*maj;
	char			*min;
	char			*bl_c;
	char			*ino;
	long int		bl_s;
	time_t			s_date;
	long			s_ns;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_ls
{
	int				first;
	t_lst			*start;
	t_flag			*flag;
}					t_ls;

char				**alloc_2d_arr(int i, int j);
char				**rewrite_inp(char **inp);
int					check_dir_and_file(char **inp);
void				print_link(t_lst *lst, char *path);
int					ft_time_help(t_lst *a, int f);
void				print4(int i);
void				print3(char *str);
void				print2(char *str);
void				print1(char *str, t_ls *ls, t_lst *lst);
void				calc_l_space(t_lst *lst);
void				calc_space(t_lst *lst);
void				calc_space2(t_lst *lst);
void				calc_space3(t_lst *lst);
void				calc_space4(t_lst *lst);
void				calc_space5(t_lst *lst);
long int			count_total(t_lst *lst);
void				print_info(t_lst *lst, char *path, t_ls *ls);
void				set_date(t_lst *lst, int f);
void				ft_record(t_lst **lst, char c, \
					char *name_s, struct stat *buff);
int					cmp_date(struct stat *buff);
void				ft_chk_type(t_ls *ls, int i, char **inp);
void				ft_chk_type_d(char *name, char *path, t_lst **lst);
void				ft_swap_lst(t_lst **lst);
void				ft_swap_lst2(t_lst **lst);
void				ft_swap_lst3(t_lst **lst);
void				ft_del_lst(t_lst **lst);
void				ft_sort(t_ls *ls, t_lst **lst, int i);
void				ft_dir_open(t_ls *ls, char *str);
void				ft_reverse_list(t_lst **head);
void				ft_time_sort(t_lst *start);
void				ft_sort_type(t_lst *start);
void				ft_ascii_sort(t_lst *start);
void				ft_ascii_sort3(t_lst *start);
void				ft_sort_error(t_lst *start);
void				ft_list_c_d(t_lst **lst, char c, \
					char *name_s, struct stat *buff);
void				ft_list_c(t_ls *ls, char c, char *name_s, \
					struct stat *buff);
void				ft_init(t_ls *ls);
void				ft_error_dir(char *str);
void				ft_error_flag(char c);
void				ft_check_inp(t_ls *ls, char **inp);
void				set_permish(struct stat	*file_stat, t_lst *obj_f);
char				*ft_itoa_base(long int value, int base);

#endif
