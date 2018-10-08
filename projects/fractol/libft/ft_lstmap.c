/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 21:10:03 by ppavlich          #+#    #+#             */
/*   Updated: 2016/12/09 21:10:05 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ptr;
	t_list *newlst;
	t_list *p_newlst;

	if (lst == NULL)
		return (NULL);
	ptr = lst;
	newlst = f(ptr);
	if (newlst == NULL)
		return (NULL);
	p_newlst = newlst;
	while (ptr->next)
	{
		ptr = ptr->next;
		p_newlst->next = f(ptr);
		if (p_newlst->next == NULL)
			return (NULL);
		p_newlst = p_newlst->next;
	}
	return (newlst);
}
