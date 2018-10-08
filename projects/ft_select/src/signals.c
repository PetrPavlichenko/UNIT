/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 20:36:54 by ppavlich          #+#    #+#             */
/*   Updated: 2017/12/14 20:36:56 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		ft_sigstp(int sig)
{
	clear_outp(g_term->sel, 1, g_term);
	reset_keypress(g_term);
	if (sig == SIGTSTP)
		ioctl(0, TIOCSTI, "\032");
	else
		ioctl(0, TIOCSTI, "\026");
	signal(sig, SIG_DFL);
}

static void		ft_continue(int sig)
{
	sig = 0;
	set_keypress(g_term);
	chk_keys(g_term->sel, *(g_term->argv1), 1, g_term);
}

static	void	ft_winsize(int sig)
{
	if (sig == SIGWINCH)
	{
		if (g_term->is_print == 1)
			clear_outp(g_term->sel, 1, g_term);
		chk_col(g_term, *(g_term->argv1));
	}
}

static void		ft_allsig(int sig)
{
	if (sig == SIGTSTP)
		ft_sigstp(sig);
	else if (sig == SIGCONT)
		ft_continue(sig);
	else if (sig == SIGWINCH)
		ft_winsize(sig);
	else
		exit_func(g_term->sel, 1, g_term);
}

void			chk_signal(t_term *term, char **argv)
{
	int i;

	i = 0;
	if (term->argv1 == 0)
		term->argv1 = &argv;
	g_term = term;
	while (++i < 32)
		signal(i, &ft_allsig);
}
