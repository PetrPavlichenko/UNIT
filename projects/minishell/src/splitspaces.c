/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitspaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 05:30:41 by ppavlich          #+#    #+#             */
/*   Updated: 2017/11/11 05:30:50 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_cwords(char const *s)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	if (s[i] == '\0')
		return (0);
	while ((s[i] >= '\t' && s[i] <= '\r') || s[i] == ' ')
		i++;
	while (s[i] != '\0')
	{
		if ((s[i] >= '\t' && s[i] <= '\r') || s[i] == ' ')
		{
			i++;
			count++;
			while ((s[i] >= '\t' && s[i] <= '\r') || s[i] == ' ')
				i++;
		}
		else
			i++;
	}
	if (!((s[i - 1] >= '\t' && s[i - 1] <= '\r') || s[i - 1] == ' '))
		count++;
	return (count);
}

char	*ft_strcreate(char const *s, char *arr, int n)
{
	int j;

	j = 0;
	while (!((s[n + j] >= '\t' && s[n + j] <= '\r') || s[n + j] == ' ')
	&& s[n + j] != '\0')
		j++;
	arr = (char *)malloc(sizeof(char) * (j + 1));
	arr[j] = '\0';
	j = 0;
	while (!((s[n] >= '\t' && s[n] <= '\r') || s[n] == ' ') && s[n] != '\0')
		arr[j++] = s[n++];
	return (arr);
}

char	**splitspaces(char const *s)
{
	char	**arr;
	size_t	i;
	int		n;
	int		j;

	if (s == NULL)
		return (0);
	i = ft_cwords(s);
	if (!(arr = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	n = 0;
	i = 0;
	while (i < ft_cwords(s))
	{
		while (((s[n] >= '\t' && s[n] <= '\r') || s[n] == ' '))
			n++;
		j = 0;
		arr[i] = ft_strcreate(s, arr[i], n);
		while (!((s[n + j] >= '\t' && s[n + j] <= '\r')
		|| s[n + j] == ' ') && s[n + j] != '\0')
			n++;
		i++;
	}
	arr[i] = 0;
	return (arr);
}
