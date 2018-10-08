/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:19:55 by ppavlich          #+#    #+#             */
/*   Updated: 2017/11/21 16:19:57 by ppavlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	norm_setenv(char **inp, char ***env, int i, int k)
{
	char	*t;
	char	*str;
	int		j;

	str = 0;
	t = ft_memalloc(i);
	t = ft_strncpy(t, inp[k], i);
	t[i] = '\0';
	j = 0;
	while ((*env)[j] && (str = ft_strnstr((*env)[j], t, i)) == NULL)
		j++;
	if (str == 0)
		(*env) = ft_add_line(*env, inp[k]);
	else
	{
		free((*env)[j]);
		(*env)[j] = ft_strdup(inp[k]);
	}
	t == NULL ? 0 : free(t);
}

void	norm_cd(char **inp, char **env, char *path, char *t)
{
	t = ft_getpwd();
	path = ft_strjoin(t, "/");
	t == NULL ? ft_error_dir(inp[1]) : free(t);
	ft_strappend(&path, inp[1]);
	chdir(path) ? chd_error(inp[1]) : 0;
	free(path);
}

void	norm_cd2(char **inp, char **env, char *path, char *t)
{
	char	*t2;
	int		i;

	i = 0;
	t = 0;
	while (env[i] && (t = ft_strnstr(env[i], "HOME", 5)) == NULL)
		i++;
	if (t)
	{
		path = (ft_strdup(t + 5));
		ft_strappend(&path, "/");
		if (inp[1] && ft_strlen(inp[1]) > 2 && inp[1][0] == '~')
		{
			t = NULL;
			t2 = path;
			t = ft_strjoin(t2, (inp[1]) + 2);
			chdir(t) ? chd_error(inp[1]) : 0;
			free(t);
		}
		else
			chdir(path) ? chd_error("~") : 0;
		free(path);
	}
	else
		home_not_set();
}

void	norm_cd3(char **inp, char **env, char *path, char *t)
{
	int	i;

	i = 0;
	while (env[i] && (t = ft_strnstr(env[i], "OLDPWD", 7)) == NULL)
		i++;
	if (t)
	{
		path = (ft_strdup(t + 7));
		chdir(path) ? chd_error(path) : 0;
		free(path);
	}
	else
		not_home();
}

void	ft_cd(char **inp, char ***env)
{
	char	*path;
	char	*pwd;
	char	*t;

	t = 0;
	path = 0;
	pwd = ft_getpwd();
	if (inp[1] && inp[1][0] != '~' && inp[1][0] != '-')
		norm_cd(inp, *env, path, t);
	else if (!inp[1] || inp[1][0] == '~')
		norm_cd2(inp, *env, path, t);
	else if (ft_strcmp(inp[1], "-") == 0)
		norm_cd3(inp, *env, path, t);
	t == NULL ? 0 : free(t);
	ft_opwd(env, pwd);
}
