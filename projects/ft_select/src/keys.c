/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:28:18 by ppavlich          #+#    #+#             */
/*   Updated: 2017/12/07 15:28:22 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		read_chr(void)
{
	int				ch;

	ch = 0;
	if (read(0, &ch, 32) <= 0)
		return (EOF);
	else
		return (ch);
}

void			set_keypress(t_term *term)
{
	struct termios new_settings;

	tcgetattr(0, &(term->dafault_term));
	new_settings = term->dafault_term;
	new_settings.c_lflag &= (~ICANON);
	new_settings.c_lflag &= (~ECHO);
	new_settings.c_cc[VTIME] = 0;
	new_settings.c_cc[VMIN] = 1;
	tcsetattr(0, TCSANOW, &new_settings);
	ft_putstr(tgetstr("vi", NULL));
	term->сur_term = new_settings;
}

void			reset_keypress(t_term *term)
{
	ft_putstr(tgetstr("ve", NULL));
	tcsetattr(0, TCSANOW, &(term->dafault_term));
}

void			chk_keys(t_selct *sel, char **argv, int fd, t_term *term)
{
	int		key;

	term->is_print == 0 ? ft_clear() : \
	clear_outp(sel, fd, term);
	chk_col(term, argv);
	print_arr(sel, argv, fd, term);
	while (1)
	{
		chk_signal(term, argv);
		term = g_term;
		key = read_chr();
		(key == 27) ? exit_func(sel, fd, term) : 0;
		if (key == 32)
			sel->selected[sel->cur_file] == '0' ? \
		sel->selected[sel->cur_file] = '1' : \
		(sel->selected[sel->cur_file] = '0');
		(key == 4283163) ? circle_inp(sel, 0) : 0;
		(key == 4348699) ? circle_inp(sel, 1) : 0;
		(key == 127 || key == 2117294875) ? ft_delete(sel) : 0;
		key == 10 ? return_outp(sel, argv, fd, term) : 0;
		term->is_print == 0 ? 0 : clear_outp(sel, fd, term);
		print_arr(sel, argv, fd, term);
	}
}
