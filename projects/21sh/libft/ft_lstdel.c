/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:38:45 by ppavlich          #+#    #+#             */
/*   Updated: 2016/12/09 19:38:49 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*nexttmp;

	tmp = *alst;
	while (tmp)
	{
		del(tmp->content, tmp->content_size);
		nexttmp = tmp->next;
		free(tmp);
		tmp = nexttmp;
	}
	tmp = NULL;
	*alst = NULL;
}
