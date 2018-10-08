/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:26:22 by ppavlich          #+#    #+#             */
/*   Updated: 2016/12/05 17:26:25 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*s1;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (s[0] == '\0')
		return ("");
	while ((s[i] == '\n' || s[i] == '\t' || s[i] == ' ') && s[i] != '\0')
		i++;
	len = ft_strlen(s) - 1;
	while ((s[len] == '\n' || s[len] == '\t' || s[len] == ' ') && len > i)
		len--;
	if ((s1 = ft_strnew(len - i + 1)) == NULL)
		return (NULL);
	while (i <= len)
		s1[j++] = s[i++];
	s1[j] = '\0';
	return (s1);
}
