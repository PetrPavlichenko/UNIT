/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 13:51:21 by ppavlich          #+#    #+#             */
/*   Updated: 2017/11/26 13:51:43 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		init_terminal(t_term *term)
{
	term->name = NULL;
	if ((term->name = getenv("TERM")) == NULL)
	{
		ft_putstr_fd("Warning $TERM does not exist", 2);
		exit(-1);
	}
	if (tgetent(NULL, term->name) <= 0)
		return (-1);
	term->width = tgetnum("li");
	term->high = tgetnum("co");
	term->max_len = 0;
	term->argv1 = 0;
	term->cols = 0;
	term->cur_col = 0;
	term->small = 0;
	term->is_print = 0;
	return (1);
}

static int		chk_termfd(void)
{
	int		fd;

	if ((fd = open(ttyname(0), O_WRONLY)) < 0)
		return (-1);
	if (!isatty(fd))
		return (-1);
	return (fd);
}

void			free_structs(t_term *term)
{
	free(term->sel->selected);
	free(term->sel->deleted);
	free(term->sel);
	free(term);
}

int				main(int argc, char **argv)
{
	t_term			*term;
	int				fd;

	argc < 2 ? arg_err() : 0;
	term = (t_term *)malloc(sizeof(t_term));
	(fd = chk_termfd()) > 0 ? 0 : term_err();
	if (!init_terminal(term))
		term_err();
	set_keypress(term);
	term->sel = set_input(argv);
	chk_keys(term->sel, argv, fd, term);
	close(fd);
	reset_keypress(term);
	free_structs(term);
	return (0);
}
